#include <iostream>
#include <vector>

int main() {
  int num = -2;
  size_t cnt = 0;
  while(num) {
    ++cnt;
    num &= num - 1;
  }
  std::cout << cnt << std::endl;

  return 0;
}