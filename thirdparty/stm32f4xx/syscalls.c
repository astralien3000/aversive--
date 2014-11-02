/**
 * @file    syscalls.c
 * @author  Florian MAZEN. Modified by Kevin JOLY
 * @version V1.1
 * @date    11/29/2013
 * @brief   newlib syscall declaration
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <stm32f4xx.h>

#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ x
#else
# define UNUSED(x) x
#endif

// Function declaration.
void _exit(int i);
int _open(const char *name, int flags, int mode);
int _read(int file, char *ptr, int len);
int _write(int file, char *buffer, unsigned int count);
int _lseek(int file, int ptr, int dir);
int _fstat(int file, struct stat *st);
int _link(char *old, char *new);
int _unlink(char *name);
int _stat(char *file, struct stat *st);
int _close(int file);
int _execve(char *name, char **argv, char **env);
int _fork();
int _getpid();
int _isatty(int file);
int _kill(int pid, int sig);
caddr_t _sbrk(int incr);
int times(struct tm *buf);
int _wait(int *status);

#undef errno
extern int errno;
char *__env[1] = {0};
char **__environ = __env;
extern unsigned int _sheap;
extern unsigned int _eheap;
static caddr_t heap = NULL;


// Function definition.

void _exit(int UNUSED(i))
{
	while (1);
}

int _write(int file, char *buffer, unsigned int count)
{
	unsigned int i;

#ifdef USART_DEBUG
	if (file == 1) {
		for (i = 0 ; i < count ; i++) {
			while(!(USART_DEBUG->SR & USART_SR_TXE));
			USART_DEBUG->DR = buffer[i];
		}
		return count;
	}
#endif
	return -1;
}

int _close(int UNUSED(file))
{
	return -1;
}

int _fstat(int UNUSED(file), struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int UNUSED(file))
{
	return 1;
}

int _lseek(int UNUSED(file), int UNUSED(ptr), int UNUSED(dir))
{
	return 0;
}

int _read(int file, char *ptr, int UNUSED(len))
{
#ifdef USART_DEBUG
	if (file == 0) { /* STDIN */
		while(!(USART_DEBUG->SR & USART_SR_RXNE))
			;
		ptr[0] = (uint8_t)(USART_DEBUG->DR);

		return 1;
	}
#endif
	return 0;
}

caddr_t _sbrk(int incr)
{
	caddr_t prevHeap;
	caddr_t nextHeap;

	if (heap == NULL)
	{ // first allocation
		heap = (caddr_t) & _sheap;
	}

	prevHeap = heap;

	// Always return data aligned on a 8 byte boundary
	nextHeap = (caddr_t) (((unsigned int) (heap + incr) + 7) & ~7);

	// Check enough space and there is no collision with stack coming the other way
	// if stack is above start of heap
	if (nextHeap >= (caddr_t) & _eheap)
	{
		errno = ENOMEM;
		return NULL; // error - no more memory
	}
	else
	{
		heap = nextHeap;
		return (caddr_t) prevHeap;
	}
}

int _open(const char *UNUSED(name), int UNUSED(flags), int UNUSED(mode))
{
	return -1;
}

int _link(char *UNUSED(old), char *UNUSED(new))
{
	errno = EMLINK;
	return -1;
}

int _unlink(char *UNUSED(name))
{
	errno = ENOENT;
	return -1;
}

int _stat(char *UNUSED(file), struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int _execve(char *UNUSED(name), char **UNUSED(argv), char **UNUSED(env))
{
	errno = ENOMEM;
	return -1;
}

int _fork()
{
	errno = EAGAIN;
	return -1;
}

int _getpid()
{
	return 1;
}

int _kill(int UNUSED(pid), int UNUSED(sig))
{
	errno = EINVAL;
	return (-1);
}

int times(struct tm *UNUSED(buf))
{
	return -1;
}

int _wait(int *UNUSED(status))
{
	errno = ECHILD;
	return -1;
}
