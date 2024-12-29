#include <bits/stdc++.h>

using namespace std;
vector<int> one = {1, 2, 3, 4, 5}, two = {2, 1, 2, 3, 2, 4, 2, 5},
            three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<pair<int, int>> st = {{0, 1}, {0, 2}, {0, 3}};

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

vector<int> solution(vector<int> answers) {
  for (int i = 0; i < answers.size(); i++) {
    if (answers[i] == one[i % one.size()])
      st[0].first++;
    if (answers[i] == two[i % two.size()])
      st[1].first++;
    if (answers[i] == three[i % three.size()])
      st[2].first++;
  }
  sort(st.begin(), st.end());

  vector<int> result;

  auto iter = st.end() - 1;
  while (iter >= lower_bound(st.begin(), st.end(), st.back(), cmp)) {
    result.push_back(iter->second);
    iter--;
  }

  sort(result.begin(), result.end());
  return result;
}