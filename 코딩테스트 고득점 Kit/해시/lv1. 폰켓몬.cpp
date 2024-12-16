#include <bits/stdc++.h>

using namespace std;

set<int> S;

int solution(vector<int> nums) {
  for (int i : nums)
    S.insert(i);
  return min(S.size(), nums.size() / 2);
}