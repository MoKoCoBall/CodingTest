#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
 public:
  vector<vector<int>> tree;
  int size;

  SegmentTree(int N) {
    size = N;
    tree.resize(4 * N);
  }

  void MERGETREE(const vector<int>& arr, int start, int end, int node) {
    if (start == end) {
      tree[node] = {arr[start]};
      return;
    }

    int mid = (start + end) / 2;

    MERGETREE(arr, start, mid, node * 2);
    MERGETREE(arr, mid + 1, end, node * 2 + 1);

    merge(tree[node * 2].begin(), tree[node * 2].end(),
          tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
          back_inserter(tree[node]));
  }

  int SOLVE(int start, int end, int node, int i, int j, int k) {
    if (j < start || end < i) {
      return 0;
    }

    if (i <= start && end <= j) {
      return tree[node].end() -
             upper_bound(tree[node].begin(), tree[node].end(), k);
    }

    int mid = (start + end) / 2;

    return SOLVE(start, mid, node * 2, i, j, k) +
           SOLVE(mid + 1, end, node * 2 + 1, i, j, k);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> V(N + 1);
  SegmentTree tree(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> V[i];
  }

  tree.MERGETREE(V, 1, N, 1);

  int M;
  cin >> M;

  int ans = 0;

  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;

    int i = a ^ ans;
    int j = b ^ ans;
    int k = c ^ ans;

    ans = tree.SOLVE(1, N, 1, i, j, k);
    cout << ans << "\n";
  }

  return 0;
}