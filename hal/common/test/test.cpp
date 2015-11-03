extern void gpio_test(void);
extern void timer_test(void);
extern void uart_test(void);

int main(int, char**) {
  gpio_test();
  timer_test();
  uart_test();
  return 0;
}
