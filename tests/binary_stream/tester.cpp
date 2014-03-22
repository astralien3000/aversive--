#include <cerrno>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>

static const char* DEVICE = "/dev/ttyACM0";

// Function from http://stackoverflow.com/questions/6947413#answer-6947758
int set_interface_attribs(int fd, int speed, int parity)
{
  struct termios tty;
  memset(&tty, 0, sizeof(tty));
  if(tcgetattr (fd, &tty) != 0) {
    return -1;
  }
  
  cfsetospeed(&tty, speed);
  cfsetispeed(&tty, speed);
  
  tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
  // disable IGNBRK for mismatched speed tests; otherwise receive break
  // as \000 chars
  tty.c_iflag &= ~IGNBRK;         // ignore break signal
  tty.c_lflag = 0;                // no signaling chars, no echo,
  // no canonical processing
  tty.c_oflag = 0;                // no remapping, no delays
  tty.c_cc[VMIN] = 0;             // read doesn't block
  tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

  tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
  // enable reading
  tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
  tty.c_cflag |= parity;
  tty.c_cflag &= ~CSTOPB;
  tty.c_cflag &= ~CRTSCTS;

  if(tcsetattr(fd, TCSANOW, &tty) != 0) {
    return -1;
  }
  return 0;
}

// Function from http://stackoverflow.com/questions/6947413#answer-6947758
void set_blocking(int fd, int should_block)
{
  struct termios tty;
  memset(&tty, 0, sizeof(tty));
  if(tcgetattr(fd, &tty) != 0) {
    return;
  }
  
  tty.c_cc[VMIN] = should_block ? 1 : 0;
  tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
  
  tcsetattr (fd, TCSANOW, &tty);
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  int fd = open(DEVICE, O_RDWR | O_NOCTTY | O_SYNC);
  if(fd < 0) {
    return EXIT_FAILURE;
  }
  
  if(set_interface_attribs(fd, B9600, 0) < 0) {
    return EXIT_FAILURE;
  }
  
  set_blocking(fd, 1);
  
  usleep(1500000);
  
  uint32_t i = 1 << 30 | 1 << 23 | 1 << 10 | 1 << 5;
  uint32_t j;
  uint8_t c;
  //printf("Sending in binary %u.\n", i);
  for(int k = 0; k < 100; k++) {
    int n;
    n = write(fd, &i, 4);
    //printf("Sent %d bits\n", n);
    n = 0;
    j = 0;
    while(n != 4) {
      n += read(fd, &c, 1);
      j += c << (8*(n-1));
    }
    //printf("Received back (%d bytes) %u.\n", n, j);
    assert(i == j);
    //sleep(1);
  }
  printf("OK\n");
  return EXIT_SUCCESS;
}
