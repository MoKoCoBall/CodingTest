#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long custom_pow(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 0)
    {
        return custom_pow(a, b / 2) * custom_pow(a, b / 2) % MOD;
    }
    else
    {
        return custom_pow(a, b / 2) * custom_pow(a, b / 2) * a % MOD;
    }
}

long long combination(long long n, long long r)
{
    long long ret = 1;

    for (long long i = 0; i < r; i++)
    {
        ret = ret * (n - i) % MOD;
    }

    for (long long i = 1; i <= r; i++)
    {
        ret = ret * custom_pow(i, MOD - 2) % MOD;
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, R;
    cin >> N >> R;

    cout << combination(N, R);

    return 0;
}