#include <bits/stdc++.h>

using namespace std;

int board[101][101];
deque<pair<int, int>> DQ;
vector<pair<int, char>> V;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time = 0;
    int idx = 0;
    int d = 0;

    int N, K;
    cin >> N >> K;

    DQ.push_back({1, 1});
    board[1][1] = 1;

    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = -1;
    }

    int L;
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int x;
        char dir;
        cin >> x >> dir;
        V.push_back({x, dir});
    }

    while (1)
    {
        auto head = DQ.front();
        int nx = head.first + dx[d];
        int ny = head.second + dy[d];

        time++;

        if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 1)
        {
            break;
        }

        if (board[nx][ny] == -1)
        {
            board[nx][ny] = 1;
            DQ.push_front({nx, ny});
        }
        else
        {
            board[nx][ny] = 1;
            board[DQ.back().first][DQ.back().second] = 0;
            DQ.push_front({nx, ny});
            DQ.pop_back();
        }

        if (V[idx].first == time)
        {
            if (V[idx].second == 'L')
            {
                d = (d + 3) % 4;
            }
            else
            {
                d = (d + 1) % 4;
            }

            idx++;
        }
    }

    cout << time;

    return 0;
}