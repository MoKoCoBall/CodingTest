#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
 public:
  vector<T> tree;
  int size;

  SegmentTree(int N) {
    tree.resize(4 * N + 1);
    size = N;
  }

  T INIT(int start, int end, int node) {
    if (start == end) {
      return tree[node] = 0;
    }

    int mid = (start + end) / 2;

    return tree[node] =
               INIT(start, mid, node * 2) + INIT(mid + 1, end, node * 2 + 1);
  }

  void UPDATE(int start, int end, int node, int index, T value) {
    if (index < start || end < index) {
      return;
    }

    tree[node] += value;

    if (start == end) {
      return;
    }

    int mid = (start + end) / 2;

    UPDATE(start, mid, node * 2, index, value);
    UPDATE(mid + 1, end, node * 2 + 1, index, value);
  }

  T SUM(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
      return 0;
    }

    if (left <= start && end <= right) {
      return tree[node];
    }

    int mid = (start + end) / 2;

    return SUM(start, mid, node * 2, left, right) +
           SUM(mid + 1, end, node * 2 + 1, left, right);
  }

  T QUERY(int left, int right) { return SUM(1, size, 1, left, right); }

  T SOLVE(int node, int start, int end, int value) {
    if (start == end) {
      return start;
    }

    int mid = (start + end) / 2;

    if (tree[node * 2] >= value) {
      return SOLVE(node * 2, start, mid, value);
    } else {
      return SOLVE(node * 2 + 1, mid + 1, end, value - tree[node * 2]);
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  const int MAX = 1000000;

  SegmentTree<int> tree(MAX);
  tree.INIT(1, MAX, 1);

  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;

    if (A == 1) {
      int B;
      cin >> B;

      int candy = tree.SOLVE(1, 1, MAX, B);
      cout << candy << "\n";
      tree.UPDATE(1, MAX, 1, candy, -1);
    } else if (A == 2) {
      int B, C;
      cin >> B >> C;
      tree.UPDATE(1, MAX, 1, B, C);
    }
  }

  return 0;
}