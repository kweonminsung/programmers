#include <bits/stdc++.h>

using namespace std;

int maxCnt = INT_MIN;

int solution(int k, vector<vector<int>> dungeons) {
  vector<int> turn;
  for (int i = 0; i < dungeons.size(); i++)
    turn.push_back(i);

  do {
    int hLeft = k, cnt = 0;
    for (int i = 0; i < dungeons.size(); i++) {
      if (dungeons[turn[i]][0] <= hLeft) {
        cnt++;
        hLeft -= dungeons[turn[i]][1];
      }
    }
    maxCnt = max(maxCnt, cnt);
  } while (next_permutation(turn.begin(), turn.end()));

  return maxCnt;
}