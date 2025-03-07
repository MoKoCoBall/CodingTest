#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, R, X;
    cin >> N >> L >> R >> X;

    vector<int> A(N);

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // N번째 비트
    for (int bit = 1; bit < (1 << N); bit++)
    {
        int sum = 0;
        int mn = INT_MAX, mx = 0;

        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                sum += A[i];
                mx = max(mx, A[i]);
                mn = min(mn, A[i]);
            }
        }

        if (sum >= L && sum <= R && (mx - mn) >= X)
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}