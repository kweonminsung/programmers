#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> D;
queue<int> Q;
int cnt = 0, w = 0;
bool flag = true;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  for (auto i : truck_weights)
    Q.push(i);

  while (!Q.empty() || !D.empty() || flag) {
    cnt++;
    flag = false;

    for (auto &x : D)
      x.second += 1;

    if (!D.empty() && D.front().second == bridge_length) {
      w -= D.front().first;
      D.pop_front();
    }

    if (!Q.empty() && bridge_length >= D.size() + 1 &&
        weight >= w + Q.front()) {
      D.push_back({Q.front(), 0});
      w += Q.front();
      Q.pop();
    }
  }
  return cnt;
}