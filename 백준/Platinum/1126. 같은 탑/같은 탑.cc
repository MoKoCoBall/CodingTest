#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> V(N);
  vector<vector<int>> dp(N + 1, vector<int>(500001, -1));

  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 500001; j++) {
      if (dp[i - 1][j] == -1) {
        continue;
      }

      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      dp[i][j + V[i - 1]] = max(dp[i][j + V[i - 1]], dp[i - 1][j] + V[i - 1]);

      if (j >= V[i - 1]) {
        dp[i][j - V[i - 1]] = max(dp[i][j - V[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][V[i - 1] - j] =
            max(dp[i][V[i - 1] - j], dp[i - 1][j] + V[i - 1] - j);
      }
    }
  }

  cout << (dp[N][0] ? dp[N][0] : -1);

  return 0;
}