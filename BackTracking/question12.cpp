#include <iostream>
#include <vector>
std::vector<std::vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
 public:
  std::vector<std::vector<char>> map;
  std::vector<std::vector<int>> trace;
  size_t width, height, strlen;
  bool find = false;

  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    if (board.empty()) {
      return false;
    }
    this->width = board.front().size();
    this->height = board.size();
    strlen = word.length();
    map.resize(height + 2);
    trace.resize(height + 2);
    for (size_t i = 0; i < height + 2; ++i) {
      map[i].resize(width + 2);
      trace[i].resize(width + 2, 0);
    }
    for (size_t i = 0; i < height; ++i) {
      for (size_t j = 0; j < width; ++j) {
        map[i + 1][j + 1] = board[i][j];
      }
    }
    size_t current_length = 0;
    for (size_t i = 1; i <= height; ++i) {
      for (size_t j = 1; j <= width; ++j) {
        trace[i][j] = 1;
        exist_bt(current_length, word, i, j);
        if (find) {
          return true;
        } else {
          trace[i][j] = 0;
        }
      }
    }
    return false;
  }

  void exist_bt(size_t current_length, std::string word, size_t si, size_t sj) {
    if (find) {
      return;
    }
    if (si <= 0 || si > height || sj <= 0 || sj > width) {
      return;
    }
    if (map[si][sj] == word[current_length]) {
      ++current_length;
      // std::cout << "find in [" << si << ", " << sj << "]" << std::endl;
      if (current_length == strlen) {
        find = true;
        return;
      } else {
        for (size_t i = 0; i < 4; ++i) {
          if (trace[si + dir[i][0]][sj + dir[i][1]] != 1) {
            trace[si + dir[i][0]][sj + dir[i][1]] = 1;
            exist_bt(current_length, word, si + dir[i][0], sj + dir[i][1]);
            trace[si + dir[i][0]][sj + dir[i][1]] = 0;
          }
        }
      }
    } else {
      return;
    }
  }
};

int main() {
  Solution s;
  std::vector<std::vector<char>> m = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::vector<std::vector<char>> m2 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::vector<std::vector<char>> m3 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string str("ABCCED");
  std::string str2("SEE");
  std::string str3("ABCB");

  std::cout << s.exist(m3, str3) << std::endl;

  return 0;
}