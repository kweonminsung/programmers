#include <bits/stdc++.h>

using namespace std;

stack<char> S;

bool solution(string s) {
  for (char c : s) {
    if (c == '(')
      S.push(c);
    else if (c == ')') {
      if (S.empty())
        return false;
      S.pop();
    }
  }
  if (!S.empty())
    return false;
  return true;
}