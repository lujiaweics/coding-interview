#include <vector>
#include <iostream>

int FindDuplicateNumber(std::vector<int> &num) {
  for (size_t i = 0; i < num.size(); ++i) {
    while (num[i] != i) {
      if (num[i] != num[num[i]]) {
        std::swap(num[i], num[num[i]]);
      } else {
        return num[i];
      }
    }
  }

  return -1;
}

int main() {
  std::vector<int> vec = {1, 2, 3 };
  std::cout << FindDuplicateNumber(vec) << std::endl;

  return 0;
}