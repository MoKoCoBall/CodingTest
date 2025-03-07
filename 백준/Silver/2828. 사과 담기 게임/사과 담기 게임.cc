#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int l = 1, r = M;
    int ans = 0;

    int J;
    cin >> J;

    for (int i = 0; i < J; i++)
    {
        int p;
        cin >> p;

        if (p < l)
        {
            ans += l - p;
            l = p;
            r = l + M - 1;
        }
        else if (p > r)
        {
            ans += p - r;
            r = p;
            l = r - M + 1;
        }
    }

    cout << ans;

    return 0;
}