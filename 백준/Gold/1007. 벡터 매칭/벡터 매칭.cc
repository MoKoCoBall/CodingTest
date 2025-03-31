#include <bits/stdc++.h>

using namespace std;

int N;
bool vis[21];
vector<pair<int, int>> V;
double ans = 2e9 + 7;

void dfs(int idx, int cnt)
{
    if (cnt == N / 2)
    {
        pair<int, int> point = {0, 0};

        for (int i = 0; i < N; i++)
        {
            if (vis[i])
            {
                point.first -= V[i].first;
                point.second -= V[i].second;
            }
            else
            {
                point.first += V[i].first;
                point.second += V[i].second;
            }
        }

        ans = min(ans, sqrt(pow(point.first, 2) + pow(point.second, 2)));

        return;
    }

    for (int i = idx; i < N; i++)
    {
        vis[i] = true;
        dfs(i + 1, cnt + 1);
        vis[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        memset(vis, false, sizeof(vis));
        V.clear();
        ans = 2e9 + 7;

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;

            V.push_back({x, y});
        }

        dfs(0, 0);

        cout << fixed << setprecision(16) << ans << "\n";
    }

    return 0;
}