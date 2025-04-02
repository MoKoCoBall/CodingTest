#include <bits/stdc++.h>

using namespace std;

int N;
int S[21][21];
bool vis[21];
int mn = INT_MAX;

int cal()
{
    int start = 0;
    int link = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (vis[i] && vis[j])
            {
                start += S[i][j];
            }
            else if (!vis[i] && !vis[j])
            {
                link += S[i][j];
            }
        }
    }

    return abs(start - link);
}

void solve(int idx, int count)
{
    if (count == N / 2)
    {
        mn = min(mn, cal());
        return;
    }

    if (idx > N)
    {
        return;
    }

    vis[idx] = true;
    solve(idx + 1, count + 1);

    vis[idx] = false;
    solve(idx + 1, count);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> S[i][j];
        }
    }

    solve(1, 0);

    cout << mn;

    return 0;
}
