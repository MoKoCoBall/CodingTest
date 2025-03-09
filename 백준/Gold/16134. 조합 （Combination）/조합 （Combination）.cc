#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long custom_pow(long long a, long long b)
{
    long long ret = 1;
    a %= MOD;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }

    return ret;
}

long long combination(long long n, long long r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }

    long long numerator = 1;
    long long denominator = 1;

    for (long long i = 0; i < r; i++)
    {
        numerator = (numerator * (n - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }

    return (numerator * custom_pow(denominator, MOD - 2)) % MOD;
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