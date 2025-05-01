#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int w, n;
  cin >> w >> n;

  vector<int> V(n, 0);
  vector<pair<int, int>> dp(400001, {0, 0});

  for (int i = 0; i < n; i++) {
    cin >> V[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dp[V[i] + V[j]] = {i, j};
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int tmp = w - V[i] - V[j];

      if (tmp < 0 || tmp > 400000) {
        continue;
      }

      if (dp[tmp].first == 0 || dp[tmp].second == 0 || dp[tmp].first == i ||
          dp[tmp].second == j || dp[tmp].first == j || dp[tmp].second == i) {
        continue;
      }

      cout << "YES";
      return 0;
    }
  }

  cout << "NO";

  return 0;
}