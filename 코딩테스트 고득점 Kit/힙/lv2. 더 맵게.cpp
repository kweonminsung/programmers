#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int cnt = 0;

int solution(vector<int> scoville, int K) {
  for (auto i : scoville)
    pq.push(i);

  while (pq.size() >= 2 && pq.top() < K) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();
    pq.push(first + second * 2);
    cnt++;
  }

  if (pq.top() < K)
    return -1;
  return cnt;
}