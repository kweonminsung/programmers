#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) { return a + b > b + a; }

string solution(vector<int> numbers) {
  vector<string> v;
  for (int n : numbers)
    v.push_back(to_string(n));
  sort(v.begin(), v.end(), cmp);

  if (v[0] == "0")
    return "0";

  string result;
  for (string s : v)
    result += s;
  return result;
}