#include <iostream>
#include <vector>

class Solution {
 public:
  void countNumbers(int cnt) {
    std::vector<int> numForEachIdx = {
        0,
    };
    numForEachIdx.reserve(cnt);
    addOne(numForEachIdx);
    while (numForEachIdx.size() != cnt + 1) {
      printVec(numForEachIdx);
      std::cout << " ";
      addOne(numForEachIdx);
    }
    std::cout << std::endl;
  }

  void printVec(std::vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
      std::cout << vec[i];
    }
  }

  void addOne(std::vector<int> &vec) {
    bool needTakeOver = 1;
    int idx = 0;
    for (idx = 0; idx < vec.size(); ++idx) {
      if (++vec[idx] == 10) {
        vec[idx] = 0;
        needTakeOver = 1;
      } else {
        needTakeOver = 0;
        break;
      }
    }
    if (idx == vec.size() && needTakeOver) {
      vec.push_back(1);
    }
  }
};

class RecursivelySolution {
 public:
  void print1ToMaxOfNDigits(const int n) {
    if (n <= 0) {
      return;
    }

    int *number = new int[n];
    constexpr size_t currentIdx = 0;
    for (size_t i = 0; i < 10; ++i) {
      number[currentIdx] = i + 0;
      print1ToMaxOfNDigitsRecursively(number, n, currentIdx + 1);
    }
    std::cout << std::endl;
  }

  void print1ToMaxOfNDigitsRecursively(int *number, const int totalLength,
                                       const size_t currentIdx) {
    if (currentIdx == totalLength) {
      printNumber(number, totalLength);
      std::cout << " ";
      return;
    }

    for (size_t i = 0; i < 10; ++i) {
      number[currentIdx] = i + 0;
      print1ToMaxOfNDigitsRecursively(number, totalLength, currentIdx + 1);
    }
  }

  void printNumber(const int *number, const size_t totalLength) {
    bool isLeadingZero = true;
    for (size_t i = 0; i < totalLength; ++i) {
      if (isLeadingZero && number[i] == 0) {
        continue;
      } else {
        isLeadingZero = false;
        std::cout << number[i];
      }
    }
  }
};

int main() {
  // Solution s;
  RecursivelySolution s;
  s.print1ToMaxOfNDigits(10);

  return 0;
}