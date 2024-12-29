#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dist[101][101];

int solution(vector<vector<int>> maps) {
  int n = maps.size(), m = maps[0].size();
  for (int i = 0; i < n; i++)
    fill(dist[i], dist[i] + m, INT_MAX);

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  dist[0][0] = 1;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (maps[nx][ny] == 0)
        continue;

      if (dist[nx][ny] > dist[cur.first][cur.second] + 1) {
        Q.push({nx, ny});
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
      }
    }
  }
  return dist[n - 1][m - 1] == INT_MAX ? -1 : dist[n - 1][m - 1];
}