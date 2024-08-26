#include <iostream>
#include <vector>

class Solution {
 public:
  int minNumberInRotateArray(std::vector<int>& nums, size_t left, size_t right) {
    if (nums.size() == 0) {
      return -1;
    } else if (nums.size() == 1) {
      return nums.front();
    }
    const int endNum = nums.back();
    int l = left, r = right;
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
          // choose recursion or linear search
          return std::min(minNumberInRotateArray(nums, 0, l),
                          minNumberInRotateArray(nums, l + 1, r));
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  std::vector vec{1, 1, 1, 1, 0, 1};
  std::cout << s.minNumberInRotateArray(vec, 0, vec.size() - 1) << std::endl;

  return 0;
}