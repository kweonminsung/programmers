#include <bits/stdc++.h>

using namespace std;

vector<int> edges[51];
unordered_map<string, int> M;
int dist[51];

int distCal(string a, string b) {
  int cnt = 0;
  for (int i = 0; i < a.length(); i++)
    if (a[i] != b[i])
      cnt++;

  return cnt;
}

int solution(string begin, string target, vector<string> words) {
  if (find(words.begin(), words.end(), target) == words.end())
    return 0;

  words.push_back(begin);
  for (int i = 0; i < words.size(); i++)
    M[words[i]] = i;

  for (int i = 0; i < words.size(); i++) {
    for (int j = i + 1; j < words.size(); j++) {
      if (distCal(words[i], words[j]) == 1) {
        edges[i].push_back(j);
        edges[j].push_back(i);
      }
    }
  }

  fill(dist, dist + words.size(), INT_MAX);
  queue<int> Q;
  Q.push(M[begin]);
  dist[M[begin]] = 0;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (auto nx : edges[cur]) {
      if (dist[nx] > dist[cur] + 1) {
        Q.push(nx);
        dist[nx] = dist[cur] + 1;
      }
    }
  }

  return dist[M[target]] == INT_MAX ? 0 : dist[M[target]];
}