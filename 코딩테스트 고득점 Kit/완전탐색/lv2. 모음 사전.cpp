#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> M{
    {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4},
};
vector<char> chars = {'A', 'E', 'I', 'O', 'U'};
int dist[5] = {781, 156, 31, 6, 1};

int solution(string word) {
  int result = 0;
  for (int i = 0; i < word.length(); i++) {
    result += 1 + M[word[i]] * dist[i];
  }
  return result;
}