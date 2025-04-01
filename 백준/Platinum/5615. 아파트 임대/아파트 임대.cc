#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull base[] = {2, 7, 61};

ull custom_pow(ull a, ull b, ull MOD)
{
    ull ret = 1;

    a %= MOD;
    b %= MOD;

    while (b)
    {
        if (b % 2)
        {
            ret = (ret * a) % MOD;
        }

        a = (a * a) % MOD;
        b /= 2;
    }

    return ret;
}

bool miller_rabin(ull n, ull a)
{
    if (a % n == 0)
    {
        return true;
    }

    ull k = n - 1;

    while (k)
    {
        ull tmp = custom_pow(a, k, n);

        if (tmp == n - 1)
        {
            return true;
        }

        if (k % 2)
        {
            return (tmp == 1 || tmp == n - 1);
        }

        k /= 2;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull N;
    ull ans = 0;
    cin >> N;

    for (ull i = 0; i < N; i++)
    {
        ull area;
        cin >> area;

        for (ull j = 0; j < 3; j++)
        {
            if (!miller_rabin(area * 2 + 1, base[j]))
            {
                ans++;
                break;
            }
        }
    }

    cout << N - ans;

    return 0;
}