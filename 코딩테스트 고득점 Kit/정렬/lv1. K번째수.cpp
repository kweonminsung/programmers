#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> result;
  for (auto c : commands) {
    vector<int> temp(c[1] - c[0] + 1);
    copy(array.begin() + c[0] - 1, array.begin() + c[1], temp.begin());
    sort(temp.begin(), temp.end());
    result.push_back(temp[c[2] - 1]);
  }

  return result;
}