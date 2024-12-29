#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int w = max(sizes[0][0], sizes[0][1]), h = sizes[0][0] + sizes[0][1] - w;

  for (auto x : sizes) {
    int tw = max(x[0], x[1]), th = x[0] + x[1] - tw;

    if (tw <= w) {
      if (th <= h)
        continue;
      h = th;
    } else {
      w = tw;
      if (th <= h)
        continue;
      h = th;
    }
  }
  return w * h;
}