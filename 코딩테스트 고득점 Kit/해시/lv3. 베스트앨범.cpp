#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> g, g1;
vector<tuple<int, int, string>> indexPlays;

bool cmp(tuple<int, int, string> a, tuple<int, int, string> b) {
  if (g[get<2>(a)] == g[get<2>(b)]) {
    if (get<1>(a) == get<1>(b))
      return get<0>(a) < get<0>(b);
    else
      return get<1>(a) > get<1>(b);
  } else
    return g[get<2>(a)] > g[get<2>(b)];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  for (int i = 0; i < genres.size(); i++) {
    g[genres[i]] += plays[i];
    indexPlays.push_back({i, plays[i], genres[i]});
  }

  sort(indexPlays.begin(), indexPlays.end(), cmp);

  vector<int> result;
  for (auto a : indexPlays) {
    if (g1[get<2>(a)] == 2)
      continue;

    result.push_back(get<0>(a));
    g1[get<2>(a)]++;
  }
  return result;
}