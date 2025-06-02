#include <bits/stdc++.h>

using namespace std;

int idx;
int node[100001];
int num[100001];
stack<int> S;
vector<int> graph[100001];
vector<vector<int>> SCC;
bool finish[100001];

int tarjan(int x) {
  node[x] = ++idx;
  S.push(x);

  int parent = node[x];

  for (int i = 0; i < graph[x].size(); i++) {
    int nxt = graph[x][i];
    if (node[nxt] == 0) {
      parent = min(parent, tarjan(nxt));
    } else if (!finish[nxt]) {
      parent = min(parent, node[nxt]);
    }
  }

  if (parent == node[x]) {
    vector<int> scc;

    while (true) {
      int tmp = S.top();
      S.pop();
      finish[tmp] = true;
      num[tmp] = SCC.size();
      scc.push_back(tmp);

      if (tmp == x) {
        break;
      }
    }

    SCC.push_back(scc);
  }

  return parent;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  int ans = 1;

  for (int i = 0; i < M; i++) {
    int x1, x2;
    cin >> x1 >> x2;

    int a = x1 > 0 ? x1 : -x1 + N;
    int b = x2 > 0 ? x2 : -x2 + N;
    int na = x1 > 0 ? x1 + N : -x1;
    int nb = x2 > 0 ? x2 + N : -x2;

    graph[na].push_back(b);
    graph[nb].push_back(a);
  }

  for (int i = 1; i <= 2 * N; i++) {
    if (node[i] == 0) {
      tarjan(i);
    }
  }

  for (int i = 1; i <= N; i++) {
    if (num[i] == num[i + N]) {
      ans = 0;
      break;
    }
  }

  cout << ans;

  return 0;
}