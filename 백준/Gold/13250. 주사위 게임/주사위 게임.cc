#include <bits/stdc++.h>

using namespace std;

double dp[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    dp[1] = 1.0;
    dp[2] = dp[1] / 6 + 1;
    dp[3] = (dp[1] + dp[2]) / 6 + 1;
    dp[4] = (dp[1] + dp[2] + dp[3]) / 6 + 1;
    dp[5] = (dp[1] + dp[2] + dp[3] + dp[4]) / 6 + 1;
    dp[6] = (dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) / 6 + 1;

    for (int i = 7; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) / 6 + 1;
    }

    cout << fixed;
    cout.precision(10);

    cout << dp[N];

    return 0;
}