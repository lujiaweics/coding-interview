#include <iostream>
#include <string>
#include <cstring>

void replaceBlank(char *src, char *dest, int old_len, int new_len) {
  char *old_p = src + old_len;
  char *new_p = dest + new_len;
  while (old_p >= src) {
    if (*old_p == ' ') {
      *new_p = '0';
      --new_p;
      *new_p = '2';
      --new_p;
      *new_p = '%';
      --new_p;
      --old_p;
    } else {
      *new_p = *old_p;
      --new_p;
      --old_p;
    }
  }
}

int main() {
  char str[] = " We are happy.";
  int len = strlen(str);
  int blank_size = 0;
  for (size_t i = 0; i < len; ++i) {
    if (str[i] == ' ') {
      ++blank_size;
    }
  }
  int new_len = len + 2 * blank_size + 1;
  char *new_str = new char[new_len];
  replaceBlank(str, new_str, len, new_len - 1);
  printf("%s\n", new_str);

  return 0;
}