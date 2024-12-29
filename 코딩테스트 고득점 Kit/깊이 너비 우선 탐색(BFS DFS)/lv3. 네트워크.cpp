#include <bits/stdc++.h>

using namespace std;

bool used[201];
int cnt = 0;

int solution(int n, vector<vector<int>> computers) {
  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;

    cnt++;
    queue<int> Q;
    Q.push(i);
    used[i] = true;

    while (!Q.empty()) {
      int nx = Q.front();
      Q.pop();

      for (int j = 0; j < n; j++) {
        if (computers[j][nx] == 0)
          continue;
        if (used[j])
          continue;
        Q.push(j);
        used[j] = true;
      }
    }
  }

  return cnt;
}