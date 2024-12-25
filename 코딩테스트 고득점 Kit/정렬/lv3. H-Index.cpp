#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
  sort(citations.begin(), citations.end());
  for (int h = citations[citations.size() - 1]; h >= 0; h--) {
    if (citations.end() - lower_bound(citations.begin(), citations.end(), h) >=
        h)
      return h;
  }
}