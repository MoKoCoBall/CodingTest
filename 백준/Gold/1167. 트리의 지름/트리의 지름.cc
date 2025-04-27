#include <bits/stdc++.h>

using namespace std;

int V;
int ans, mxnode;
vector<vector<pair<int, int>>> edges;
vector<bool> vis;

void dfs(int node, int dist) {
  if (dist > ans) {
    ans = dist;
    mxnode = node;
  }

  vis[node] = true;

  for (auto [nxt, cost] : edges[node]) {
    if (!vis[nxt]) {
      dfs(nxt, dist + cost);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> V;

  edges.resize(V + 1);
  vis.resize(V + 1, false);

  for (int i = 0; i < V; i++) {
    int u;
    cin >> u;

    while (1) {
      int v, w;
      cin >> v;
      if (v == -1) {
        break;
      }
      cin >> w;

      edges[u].push_back({v, w});
      edges[v].push_back({u, w});
    }
  }

  dfs(1, 0);
  fill(vis.begin(), vis.end(), false);
  dfs(mxnode, 0);

  cout << ans;

  return 0;
}