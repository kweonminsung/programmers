#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> s;
vector<int> result;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  for (int i = progresses.size() - 1; i >= 0; i--)
    s.push({progresses[i], i});

  while (!s.empty()) {
    int cnt = 1;
    auto top = s.top();
    int mul = ceil(double(100 - top.first) / speeds[s.top().second]);
    s.pop();

    while (!s.empty() && 100 <= s.top().first + mul * speeds[s.top().second]) {
      cnt++;
      s.pop();
    }
    result.push_back(cnt);
  }
  return result;
}