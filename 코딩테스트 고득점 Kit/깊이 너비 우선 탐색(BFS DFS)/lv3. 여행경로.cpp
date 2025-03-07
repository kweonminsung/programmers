#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

vector<vector<string>> ticket;
bool used[MAX];
vector<string> ans;
bool isFinished = false;

void func(string start, int ticketCnt) {
  ans.push_back(start);

  if (ticketCnt == ticket.size()) {
    isFinished = true;
  }

  for (int i = 0; i < ticket.size(); i++) {
    if (used[i])
      continue;
    if (ticket[i][0] != start)
      continue;

    used[i] = true;
    func(ticket[i][1], ticketCnt + 1);

    if (!isFinished) {
      ans.pop_back();
      used[i] = false;
    }
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  sort(tickets.begin(), tickets.end());

  ticket = tickets;
  func("ICN", 0);

  return ans;
}