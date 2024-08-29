#include <iostream>
#include <vector>
#include <array>
#include <string>
const int N = 10086 + 10;

void minus(std::array<int, N> &numAInverse, const size_t lenA,
           std::array<int, N> &numBInverse, const size_t lenB) {
  int needTakeOver = 0;
  size_t maxLen = std::max(lenA, lenB);
  for (size_t i = 0; i < maxLen; ++i) {
    numAInverse[i] -= numBInverse[i] + needTakeOver;
    if (numAInverse[i] < 0) {
      numAInverse[i] += 10;
      needTakeOver = 1;
    } else {
      needTakeOver = 0;
    }
  }

  return;
}

int main() {
  std::string a, b;
  std::cin >> a >> b;
  size_t lenA = a.size();
  size_t lenB = b.size();

  std::array<int, N> numAInverse, numBInverse;
  for (size_t i = 0; i < lenA; ++i) {
    numAInverse[i] = a[lenA - i - 1] - '0';
  }
  for (size_t i = 0; i < lenB; ++i) {
    numBInverse[i] = b[lenB - i - 1] - '0';
  }

  // remove leading zero
  for (size_t i = lenA - 1; i > 0; i--) {
    if (numAInverse[i] == 0) {
      lenA--;
    } else {
      break;
    }
  }
   for (size_t i = lenB - 1; i > 0; i--) {
    if (numBInverse[i] == 0) {
      lenB--;
    } else {
      break;
    }
  }
  bool aIsBiger = true;
  if (lenA < lenB) {
    aIsBiger = false;
  } else if (lenA == lenB) {
    for (int i = lenA - 1; i >= 0; i--) {
      if (numBInverse[i] > numAInverse[i]) {
        aIsBiger = false;
        break;
      }
    }
  }

  if (aIsBiger) {
    minus(numAInverse, lenA, numBInverse, lenB);
  } else {
    minus(numBInverse, lenB, numAInverse, lenA);
  }
  
  if (!aIsBiger) {
    std::cout << "-";
    numAInverse = numBInverse;
  }
  std::array<int, N> &outputNum = numAInverse;
  if (!aIsBiger) {
    outputNum = numBInverse;
  }
  bool isLeadingZero = true;
  size_t maxLen = std::max(lenA, lenB);
  for (int i = maxLen - 1; i >= 0; --i) {
    if (isLeadingZero && outputNum[i] == 0 && i != 0) {
      continue;
    } else {
      isLeadingZero = false;
      std::cout << outputNum[i];
    }
  }
  std::cout << std::endl;

  return 0;
}