#include <stdio.h>

char *print_os(void) {
#ifdef __APPLE__
  return "apple";
#elif __WINDOWS__
  return "windows";
#elif __linux__
  return "linux";
#else
  return "undef";
#endif
}

char *print_arch(void) {
#ifdef __arm__
  return "arm";
#elif __amd64__
  return "amd64";
#elif __x86_64__
  return "x86_64";
#elif __aarch64__
  return "arm";
#else
  return "undef";
#endif
}

int pointer_size(void) {
  int *pointer;
  return sizeof(pointer);
}

int pointer_width(int pointer_size) { return pointer_size * 8; }

int main(void) {
  printf("os: %s\n", print_os());
  printf("arch: %s\n", print_arch());

  int p_size = pointer_size();

  printf("Pointer size: %d\n", p_size);
  printf("Pointer width: %d\n", pointer_width(p_size));
  return 0;
}
