#include <bits/stdc++.h>

using namespace std;

vector<char> cs;
int result = 0;
set<int> resultS;

bool isPrime(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i <= sqrt(num); i++)
    if (num % i == 0)
      return false;

  return true;
}

int solution(string numbers) {
  for (char c : numbers)
    cs.push_back(c);
  sort(cs.begin(), cs.end());

  for (int i = 1; i <= cs.size(); i++) {
    vector<int> t;
    for (int j = 1; j <= cs.size() - i; j++)
      t.push_back(0);

    for (int j = 1; j <= i; j++)
      t.push_back(1);

    do {
      vector<char> avail;
      for (int k = 0; k < cs.size(); k++)
        if (t[k])
          avail.push_back(cs[k]);

      vector<int> use;
      for (int k = 0; k < avail.size(); k++)
        use.push_back(k);

      do {
        string str;
        for (int l = 0; l < use.size(); l++)
          str.push_back(avail[use[l]]);

        int parsedInt = stoi(str);
        if (isPrime(parsedInt) && resultS.find(parsedInt) == resultS.end()) {
          resultS.insert(parsedInt);
          result++;
        }
      } while (next_permutation(use.begin(), use.end()));

    } while (next_permutation(t.begin(), t.end()));
  }

  return result;
}
