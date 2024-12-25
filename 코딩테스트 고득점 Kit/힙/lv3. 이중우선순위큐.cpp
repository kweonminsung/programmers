#include <bits/stdc++.h>
#include <sstream>

using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;
unordered_map<int, int> M;
char op;
int num;

vector<int> solution(vector<string> operations) {
  stringstream ss;
  for (string s : operations) {
    ss << s;
    ss >> op >> num;
    ss.clear();

    if (op == 'I') {
      maxpq.push(num);
      minpq.push(num);
      M[num]++;
    } else {
      if (num == 1) {
        while (!maxpq.empty() && M[maxpq.top()] == 0)
          maxpq.pop();
        if (!maxpq.empty())
          M[maxpq.top()]--;
      } else {
        while (!minpq.empty() && M[minpq.top()] == 0)
          minpq.pop();
        if (!minpq.empty())
          M[minpq.top()]--;
      }
    }
  }
  while (!maxpq.empty() && M[maxpq.top()] == 0)
    maxpq.pop();
  while (!minpq.empty() && M[minpq.top()] == 0)
    minpq.pop();

  return {maxpq.empty() ? 0 : maxpq.top(), minpq.empty() ? 0 : minpq.top()};
}