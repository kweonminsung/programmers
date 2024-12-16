#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> p;

string solution(vector<string> participant, vector<string> completion) {
  for (auto s : participant)
    p[s]++;
  for (auto s : completion)
    p[s]--;

  for (auto s : participant)
    if (p[s] == 1)
      return s;
}