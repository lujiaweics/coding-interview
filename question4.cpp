#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int row = 0;
  int col = 0;

  bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
    this->row = plants.size();
    if (this->row == 0) {
      return false;
    }
    this->col = plants[0].size();
    if (this->col == 0) {
      return false;
    }
    if (target < plants[0][0] || target > plants[row - 1][col - 1]) {
      return false;
    }

    int now_row = this->row - 1;
    int now_col = 0;
    while (true) {
      if (now_col >= this->col || now_row < 0) {
        return false;
      }
      if (plants[now_row][now_col] == target) {
        std::cout << "row = " << now_row << ", col = " << now_col << std::endl;
        return true;
      } else if (plants[now_row][now_col] >= target) {
        --now_row;
      } else {
        ++now_col;
      }
    }
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> plants = {{1, 2, 3, 4, 5},
                                          {6, 7, 8, 9, 10},
                                          {11, 12, 13, 14, 15},
                                          {16, 17, 18, 19, 20},
                                          {21, 22, 23, 24, 25}};
  int target = 19;
  Solution s;
  std::cout << s.findTargetIn2DPlants(plants, target) << std::endl;

  return 0;
}