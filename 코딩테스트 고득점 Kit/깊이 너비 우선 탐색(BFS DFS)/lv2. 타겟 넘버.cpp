#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int target) {
  int cnt = 0;
  for (int i = 0; i <= numbers.size(); i++) {
    vector<int> op;
    for (int j = 0; j < i; j++)
      op.push_back(0);
    for (int j = 0; j < numbers.size() - i; j++)
      op.push_back(1);

    do {
      int tot = 0;
      for (int j = 0; j < numbers.size(); j++) {
        if (op[j] == 0)
          tot += numbers[j];
        else
          tot -= numbers[j];
      }
      if (tot == target)
        cnt++;
    } while (next_permutation(op.begin(), op.end()));
  }

  return cnt;
}