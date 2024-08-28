#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
char map[9][9];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, t, di, dj;
int escape;
void dfs(int si, int sj, int cnt);
int main() {
  int i, j;
  int si, sj;
  while (scanf("%d%d%d", &n, &m, &t) && (n || m || t)) {
    int wall = 0;
    getchar();
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%c", &map[i][j]);
        if (map[i][j] == 'X') {
          wall++;
        } else if (map[i][j] == 'S') {
          si = i;
          sj = j;
        } else if (map[i][j] == 'D') {
          di = i;
          dj = j;
        }
      }
      getchar();
    }
    if (n * m - wall < 0) {
      printf("NO\n");
      continue;
    }
    escape = 0;
    map[si][sj] = 'X';
    dfs(si, sj, 0);
    if (escape) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
void dfs(int si, int sj, int cnt) {
  int i, flag;
  if (si > n || si <= 0 || sj > m || sj <= 0) {
    return;
  }
  if (cnt == t && si == di && sj == dj) {
    escape = 1;
  }
  if (escape) {
    return;
  }
  flag = (t - cnt) - abs(si - di) - abs(sj - dj);  // 最短路剪枝
  if (flag < 0 || flag % 2)                        // 奇偶性剪枝
  {
    return;
  }
  for (i = 0; i < 4; i++) {
    if (map[si + dir[i][0]][sj + dir[i][1]] != 'X') {
      map[si + dir[i][0]][sj + dir[i][1]] = 'X';
      dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);
      map[si + dir[i][0]][sj + dir[i][1]] = '.';
    }
  }
  return;
}