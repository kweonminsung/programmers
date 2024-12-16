#include <bits/stdc++.h>
#include <string>

using namespace std;

unordered_map<string, int> m;
set<string> s;

int solution(vector<vector<string>> clothes) {
  for (auto c : clothes) {
    m[c[1]]++;
    s.insert(c[1]);
  }

  int mul = 1;
  for (auto ct : s)
    mul *= (m[ct] + 1);

  return mul - 1;
}