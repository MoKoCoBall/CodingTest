#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  cin >> S;

  int ans = 0;

  for (int i = 0; i < S.size() - 1; i++) {
    if (S[i] == S[i + 1]) {
      continue;
    }

    ans++;
  }

  cout << (ans + 1) / 2;

  return 0;
}