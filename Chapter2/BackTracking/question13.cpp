#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <functional>
#include <random>
std::vector<std::vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
 public:
  std::map<std::pair<int, int>, int> vis;
  int maxRow;
  int maxCol;
  int cnt = 0;

  int movingCount(int m, int n, int k) {
    this->maxRow = m;
    this->maxCol = n;
    this->cnt = 0;
    vis.clear();
    dfs(0, 0, k);
    return this->cnt;
  }

  void dfs(int row, int col, int k) {
    if (row < 0 || row >= maxRow || col < 0 || col >= maxCol) {
      return;
    }
    if (vis.find(std::make_pair(row, col)) == vis.end()) {
      if (check(row, col, k)) {
        vis[std::make_pair(row, col)] = 1;
        // std::cout << "i = " << row << ", col = " << col << std::endl;
        ++this->cnt;
        for (size_t i = 0; i < 4; ++i) {
          dfs(row + dir[i][0], col + dir[i][1], k);
        }
      }
    }
  }

  bool check(int row, int col, int k) {
    auto sum = 0ll;
    while (row > 0) {
      sum += row % 10;
      row /= 10;
    }
    while (col > 0) {
      sum += col % 10;
      col /= 10;
    }
    if (sum > k) {
      return false;
    } else {
      return true;
    }
    return false;
  }
};

class Solution2 {
 public:
  int movingCount(const int m, const int n, int k) {
    std::vector<std::vector<int>> vis(m, std::vector<int>(n));
    auto f = [](int x) { return x / 10 + x % 10; };
    std::function<int(int i, int j)> dfs = [&](int i, int j) -> int {
      if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || f(i) + f(j) > k) {
        return false;
      }
      vis[i][j] = true;
      return 1 + dfs(i + 1, j) + dfs(i, j + 1);
    };
    return dfs(0, 0);
  }
};

int main() {
  Solution s;
  Solution2 s2;

  // 初始化随机数引擎
  std::random_device rd;   // 非确定性随机数生成器
  std::mt19937 gen(rd());  // 以 rd() 作为种子的 Mersenne Twister 生成器

  // 定义随机数分布
  std::uniform_int_distribution<> dist_mn(1, 100);  // 1到100的均匀分布
  std::uniform_int_distribution<> dist_k(0, 20);    // 0到20的均匀分布

  for (size_t i = 0; i < 50; ++i) {
    // 生成随机数
    int m = dist_mn(gen);
    int n = dist_mn(gen);
    int k = dist_k(gen);
    auto result1 = s.movingCount(m, n, k);
    auto result2 = s2.movingCount(m, n, k);
    std::cout << static_cast<int>(result1 == result2) << ", m = " << m << ", n = " << n << ", k = " << k
              << ", result1 = " << result1 << ", result2 = " << result2
              << std::endl;
  }

  return 0;
}