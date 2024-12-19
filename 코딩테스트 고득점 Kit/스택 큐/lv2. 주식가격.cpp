#include <bits/stdc++.h>

using namespace std;

vector<int> result;

vector<int> solution(vector<int> prices) {
  int ln = prices.size();
  for (int i = 0; i < ln; i++) {
    bool flag = true;
    for (int j = i + 1; j < ln; j++) {
      if (prices[j] < prices[i]) {
        result.push_back(j - i);
        flag = false;
        break;
      }
    }

    if (flag)
      result.push_back(ln - i - 1);
  }
  return result;
}