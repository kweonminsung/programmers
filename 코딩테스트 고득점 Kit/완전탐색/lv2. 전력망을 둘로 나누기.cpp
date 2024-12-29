#include <bits/stdc++.h>

using namespace std;

int cnt = 0, result = INT_MAX;
vector<int> edges[101];
bool checked[101];

void traverse(vector<int> edges[], int loc) {
  checked[loc] = true;
  cnt++;

  for (int x : edges[loc]) {
    if (checked[x])
      continue;
    traverse(edges, x);
  }
}

int solution(int n, vector<vector<int>> wires) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++)
      edges[j].clear();

    for (int j = 0; j < n - 1; j++) {
      if (j == i)
        continue;
      edges[wires[j][0]].push_back(wires[j][1]);
      edges[wires[j][1]].push_back(wires[j][0]);
    }

    fill(checked, checked + 101, 0);
    cnt = 0;

    traverse(edges, wires[i][0]);

    result = min(result, abs(n - 2 * cnt));
  }

  return result;
}