#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
vector<vector<int>> scc;
stack<int> S;
int id, df[10001];
bool fin[10001];

int dfs(int u) {
  df[u] = ++id;
  S.push(u);

  int parent = df[u];

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    int nxt = df[v];

    if (nxt == 0) {
      parent = min(parent, dfs(v));
    } else if (!fin[v]) {
      parent = min(parent, nxt);
    }
  }

  if (parent == df[u]) {
    vector<int> V;

    while (true) {
      int tmp = S.top();
      S.pop();
      fin[tmp] = true;
      V.push_back(tmp);

      if (tmp == u) {
        break;
      }
    }

    scc.push_back(V);
  }

  return parent;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
  }

  for (int i = 1; i <= V; i++) {
    if (df[i] == 0) {
      dfs(i);
    }
  }

  for (int i = 0; i < scc.size(); i++) {
    sort(scc[i].begin(), scc[i].end());
  }

  sort(scc.begin(), scc.end());

  cout << scc.size() << "\n";
  for (int i = 0; i < scc.size(); i++) {
    for (int j = 0; j < scc[i].size(); j++) {
      cout << scc[i][j] << " ";
    }
    cout << "-1\n";
  }

  return 0;
}