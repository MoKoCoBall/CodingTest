#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
const int MOD = 10007;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  cin >> S;

  for (int i = 0; i < S.size(); i++) {
    dp[i][i] = 1;
  }

  for (int i = 0; i < S.size() - 1; i++) {
    if (S[i] == S[i + 1]) {
      dp[i][i + 1] = 3;
    } else {
      dp[i][i + 1] = 2;
    }
  }

  for (int i = 2; i < S.size(); i++) {
    for (int j = 0; j < S.size() - i; j++) {
      dp[j][j + i] =
          (dp[j + 1][j + i] + dp[j][j + i - 1] - dp[j + 1][j + i - 1] + MOD) %
          MOD;
      if (S[j] == S[j + i]) {
        dp[j][j + i] = (dp[j][j + i] + dp[j + 1][j + i - 1] + 1 + MOD) % MOD;
      }
    }
  }

  cout << dp[0][S.size() - 1];

  return 0;
}