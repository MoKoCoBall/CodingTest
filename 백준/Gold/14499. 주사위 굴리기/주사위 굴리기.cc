#include <bits/stdc++.h>

using namespace std;

int board[21][21];
int cmd[1001];
int dice[7];

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        cin >> cmd[i];
    }

    int idx = 0;

    while (idx < K)
    {
        int dir = cmd[idx++];

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        {
            continue;
        }

        // 1번 동쪽
        if (dir == 1)
        {
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }
        // 2번 서쪽
        else if (dir == 2)
        {
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }
        // 3번 북쪽
        else if (dir == 3)
        {
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }
        // 4번 남쪽
        else if (dir == 4)
        {
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }

        x = nx;
        y = ny;

        if (board[x][y] == 0)
        {
            board[x][y] = dice[6];
        }
        else
        {
            dice[6] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[1] << "\n";
    }

    return 0;
}