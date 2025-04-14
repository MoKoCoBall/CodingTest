#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long dp[101][101][101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, L, R;
  cin >> N >> L >> R;

  dp[1][1][1] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= L; j++) {
      for (int k = 1; k <= R; k++) {
        // 가려지는 경우, 왼쪽, 오른쪽
        dp[i][j][k] = (dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] +
                       dp[i - 1][j][k - 1]) %
                      MOD;
      }
    }
  }

  cout << dp[N][L][R] << "\n";

  return 0;
}