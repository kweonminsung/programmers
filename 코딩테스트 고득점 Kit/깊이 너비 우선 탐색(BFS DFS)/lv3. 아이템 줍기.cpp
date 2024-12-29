#include <bits/stdc++.h>
#define MAX 2 * 51

using namespace std;

int board[MAX][MAX], newBoard[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY,
             int itemX, int itemY) {
  for (auto r : rectangle) {
    for (int i = 2 * r[0]; i <= 2 * r[2]; i++)
      for (int j = 2 * r[1]; j <= 2 * r[3]; j++)
        board[i][j] = 1;
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (board[i][j] == 1) {
        if ((i - 1 > 0 && board[i - 1][j] == 1) &&
            (i + 1 < MAX && board[i + 1][j] == 1) &&
            (j - 1 > 0 && board[i][j - 1] == 1) &&
            (j + 1 < MAX && board[i][j + 1] == 1) &&
            (i - 1 > 0 && j - 1 > 0 && board[i - 1][j - 1] == 1) &&
            (i + 1 < MAX && j - 1 > 0 && board[i + 1][j - 1] == 1) &&
            (i + 1 < MAX && j + 1 < MAX && board[i + 1][j + 1] == 1) &&
            (i + 1 < MAX && j + 1 < MAX && board[i - 1][j + 1] == 1))
          newBoard[i][j] = 0;
        else
          newBoard[i][j] = 1;
      } else
        newBoard[i][j] = 0;
    }
  }

  // for (int i = MAX - 1; i >= 0; i--) {
  //   for (int j = 0; j < MAX; j++) {
  //     cout << (newBoard[j][i] == 0 ? " " : "1") << " ";
  //   }
  //   cout << "\n";
  // }

  for (int i = 0; i < MAX; i++)
    fill(dist[i], dist[i] + MAX, INT_MAX);

  queue<pair<int, int>> Q;
  Q.push({2 * characterX, 2 * characterY});
  dist[2 * characterX][2 * characterY] = 0;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
        continue;
      if (newBoard[nx][ny] == 0)
        continue;

      if (dist[nx][ny] > dist[cur.first][cur.second] + 1) {
        Q.push({nx, ny});
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
      }
    }
  }

  return dist[2 * itemX][2 * itemY] / 2;
}