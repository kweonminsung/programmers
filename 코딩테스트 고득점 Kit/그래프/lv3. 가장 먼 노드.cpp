#include <bits/stdc++.h>
#define MAX 20001

using namespace std;

vector<int> E[MAX];
int dist[MAX];

int solution(int n, vector<vector<int>> edge) {
  for (auto i : edge) {
    E[i[0]].push_back(i[1]);
    E[i[1]].push_back(i[0]);
  }

  fill(dist, dist + MAX, -1);

  queue<int> Q;
  dist[1] = 0;
  Q.push(1);

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (auto nx : E[cur]) {
      if (dist[nx] != -1)
        continue;

      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }

  // for (int i = 1; i <= n; i++)
  //   cout << dist[i] << " ";
  // cout << "\n";
  return count(dist + 1, dist + n + 1, *max_element(dist + 1, dist + n));
}