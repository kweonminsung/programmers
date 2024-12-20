#include <bits/stdc++.h>

using namespace std;
using t = tuple<int, int, int>;

struct cmp {
  bool operator()(t a, t b) {
    if (get<2>(a) == get<2>(b)) {
      if (get<1>(a) == get<1>(b))
        return get<0>(a) > get<0>(b);
      return get<1>(a) > get<1>(b);
    }
    return get<2>(a) > get<2>(b);
  }
};

bool cmp1(t a, t b) { return get<1>(a) < get<1>(b); }

priority_queue<t, vector<t>, cmp> pq;
vector<t> timeTable;
int now = 0, tableIndex = 0, running = -1, result = 0;

int solution(vector<vector<int>> jobs) {
  for (int i = 0; i < jobs.size(); i++)
    timeTable.push_back({i, jobs[i][0], jobs[i][1]});
  sort(timeTable.begin(), timeTable.end(), cmp1);

  while (true) {
    while (tableIndex < jobs.size() && get<1>(timeTable[tableIndex]) == now) {
      pq.push(timeTable[tableIndex]);
      tableIndex++;
    }

    if (running != -1)
      jobs[running][1]--;
    if (running != -1 && jobs[running][1] == 0) {
      result += now - jobs[running][0];
      running = -1;
    }
    if (running == -1 && !pq.empty()) {
      running = get<0>(pq.top());
      pq.pop();
    }

    if (pq.empty() && running == -1 && tableIndex == jobs.size())
      break;
    now++;
  }

  return result / jobs.size();
}