#include <bits/stdc++.h>

using namespace std;

vector<int> v;

vector<int> solution(vector<int> arr) {
  for (auto a : arr) {
    if (v.size() > 0 && v.back() == a)
      continue;
    v.push_back(a);
  }

  return v;
}