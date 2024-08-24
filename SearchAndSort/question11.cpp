#include <iostream>
#include <vector>

class Solution {
 public:
  int minNumberInRotateArray(std::vector<int>& nums) {
    if (nums.size() == 0) {
      return -1;
    } else if (nums.size() == 1) {
      return nums.front();
    }
    const int endNum = nums.back();
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      if (l == r) {
        return nums[l];
      }
      int mid = (l + r) / 2;
      if (nums[mid] > endNum) {
        l = mid + 1;
      } else if (nums[mid] < endNum) {
        r = mid;
      } else {
        if (r - l == 1) {
          return std::min(nums[l], nums[r]);
        }
        if (nums[mid - 1] > nums[mid]) {
          return nums[mid];
        } else if (nums[mid + 1] < nums[mid]) {
          return nums[mid + 1];
        } else {
          r = mid;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  std::vector vec{3, 100, 200, 3};
  std::cout << s.minNumberInRotateArray(vec) << std::endl;

  return 0;
}