#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> Q;
deque<int> D;
int cnt = 1;

int solution(vector<int> priorities, int location) {
  for (int i = 0; i < priorities.size(); i++)
    Q.push({priorities[i], i});
  for (auto i : priorities)
    D.push_back(i);
  sort(D.begin(), D.end(), greater<int>());

  while (!Q.empty()) {
    auto front = Q.front();

    if (D.front() > front.first) {
      Q.push(front);
      Q.pop();
    } else {
      if (front.second == location)
        return cnt;
      D.pop_front();
      Q.pop();
      cnt++;
    }
  }
}