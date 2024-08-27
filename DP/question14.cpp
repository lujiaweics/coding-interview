// https://leetcode.cn/problems/jian-sheng-zi-lcof/solutions/1794015/jian-sheng-zi-by-leetcode-solution-xku9/
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <vector>

class Solution {
 public:
  int cuttingBamboo(int bamboo_len) {
    if (bamboo_len <= 0) {
      return 0;
    } else if (bamboo_len == 1) {
      return 0;
    } else if (bamboo_len == 2) {
      return 1;
    } else if (bamboo_len == 3) {
      return 2;
    }
    auto* result = new long long[bamboo_len + 10];
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    for (size_t i = 4; i <= bamboo_len; ++i) {
      auto max = 0ll;
      for (size_t j = 1; j <= i / 2; ++j) {
        // std::cout << "j = " << j << ", i = " << i
        //           << ", a * b = " << result[i - j] << " x " << result[j]
        //           << std::endl;
        max = std::max(max, result[i - j] * result[j]);
      }
      result[i] = max;
    }

    return result[bamboo_len];
  }
};

int main() {
  Solution s;
  std::cout << s.cuttingBamboo(12) << std::endl;

  return 0;
}