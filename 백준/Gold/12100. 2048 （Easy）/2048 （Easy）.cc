#include <bits/stdc++.h>

using namespace std;

int board[21][21];
int N;
int ans = -1;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void move(int arr[21][21], int dir) {
  // 각각 상 하 좌 우
  if (dir == 0) {
    for (int j = 0; j < N; j++) {
      int cur = 0;
      for (int i = 1; i < N; i++) {
        if (arr[i][j] == 0) continue;

        int tmp = arr[i][j];
        arr[i][j] = 0;

        if (arr[cur][j] == 0) {
          arr[cur][j] = tmp;
        } else if (arr[cur][j] == tmp) {
          arr[cur][j] *= 2;
          cur++;
        } else {
          cur++;
          arr[cur][j] = tmp;
        }
      }
    }
  } else if (dir == 1) {
    for (int j = 0; j < N; j++) {
      int cur = N - 1;
      for (int i = N - 2; i >= 0; i--) {
        if (arr[i][j] == 0) continue;

        int tmp = arr[i][j];
        arr[i][j] = 0;

        if (arr[cur][j] == 0) {
          arr[cur][j] = tmp;
        } else if (arr[cur][j] == tmp) {
          arr[cur][j] *= 2;
          cur--;
        } else {
          cur--;
          arr[cur][j] = tmp;
        }
      }
    }
  } else if (dir == 2) {
    for (int i = 0; i < N; i++) {
      int cur = 0;
      for (int j = 1; j < N; j++) {
        if (arr[i][j] == 0) continue;

        int tmp = arr[i][j];
        arr[i][j] = 0;

        if (arr[i][cur] == 0) {
          arr[i][cur] = tmp;
        } else if (arr[i][cur] == tmp) {
          arr[i][cur] *= 2;
          cur++;
        } else {
          cur++;
          arr[i][cur] = tmp;
        }
      }
    }
  } else if (dir == 3) {
    for (int i = 0; i < N; i++) {
      int cur = N - 1;
      for (int j = N - 2; j >= 0; j--) {
        if (arr[i][j] == 0) continue;

        int tmp = arr[i][j];
        arr[i][j] = 0;

        if (arr[i][cur] == 0) {
          arr[i][cur] = tmp;
        } else if (arr[i][cur] == tmp) {
          arr[i][cur] *= 2;
          cur--;
        } else {
          cur--;
          arr[i][cur] = tmp;
        }
      }
    }
  }
}

void dfs(int arr[21][21], int cnt) {
  if (cnt == 5) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        ans = max(ans, arr[i][j]);
      }
    }
    return;
  }

  int temp[21][21];

  for (int dir = 0; dir < 4; dir++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        temp[i][j] = arr[i][j];
      }
    }

    move(arr, dir);
    dfs(arr, cnt + 1);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        arr[i][j] = temp[i][j];
      }
    }
  }
}

void solve() {
  input();
  dfs(board, 0);

  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}