#include <bits/stdc++.h>

using namespace std;

int N, K;
bool vis[500001][2];

queue<pair<int, int>> Q;

int bfs() {
  Q.push({N, 0});
  vis[N][0] = true;

  while (!Q.empty()) {
    int cur = Q.front().first;
    int time = Q.front().second;
    Q.pop();

    int nxtK = K + time * (time + 1) / 2;

    if (nxtK > 500000) {
      return -1;
    };

    if (vis[nxtK][time % 2]) {
      return time;
    };

    time++;

    for (auto nxt : {cur + 1, cur - 1, cur * 2}) {
      if (nxt < 0 || nxt > 500000 || vis[nxt][time % 2]) {
        continue;
      }
      Q.push({nxt, time});
      vis[nxt][time % 2] = true;
    }
  }

  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  cout << bfs();

  return 0;
}