#include <stddef.h>
#include <stdio.h>

const char *print_os(void) {
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

const char *print_arch(void) {
#if defined(__aarch64__) || defined(__arm64__)
  return "aarch64";
#elif defined(__x86_64__)
  return "x86_64";
#elif defined(__arm__)
  return "arm";
#else
  return "unknown";
#endif
}

size_t pointer_size(void) { return sizeof(void *); }

int pointer_width(int pointer_size) { return pointer_size * 8; }

int main(void) {
  printf("os: %s\n", print_os());
  printf("arch: %s\n", print_arch());

  int p_size = pointer_size();

  printf("Pointer size: %d\n", p_size);
  printf("Pointer width: %d\n", pointer_width(p_size));
  return 0;
}
