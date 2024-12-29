#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<int> divs;
  for (int i = 1; i <= sqrt(yellow); i++)
    if (yellow % i == 0)
      divs.push_back(i);

  for (int div : divs) {
    int w = yellow / div, h = div;

    if (4 + 2 * w + 2 * h == brown)
      return {w + 2, h + 2};
  }
}