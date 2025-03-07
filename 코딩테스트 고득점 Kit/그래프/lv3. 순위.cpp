#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> graph;

int solution(int n, vector<vector<int>> results) {
  graph.assign(n + 1, vector<bool>(n + 1, false));

  for (auto i : results) {
    graph[i[0]][i[1]] = true;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (graph[j][i] && graph[i][k])
          graph[j][k] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] || graph[j][i])
        cnt++;
    }
    if (cnt == n - 1)
      ans++;
  }

  return ans;
}