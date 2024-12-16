#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
  sort(phone_book.begin(), phone_book.end());

  for (int i = 0; i < phone_book.size() - 1; i++) {
    if (phone_book[i].length() > phone_book[i + 1].length() &&
        phone_book[i + 1].compare(
            phone_book[i].substr(0, phone_book[i + 1].length())) == 0)
      return false;
    else if (phone_book[i].compare(
                 phone_book[i + 1].substr(0, phone_book[i].length())) == 0)
      return false;
  }

  return true;
}