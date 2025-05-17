#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
  ll x, y;

  bool operator<(const Point& p) const {
    if (y != p.y) return y < p.y;
    return x < p.x;
  }
};

vector<pair<Point, int>> V;

ll dist(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

ll ccw(Point p1, Point p2, Point p3) {
  return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
         (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

bool compare(pair<Point, int> p1, pair<Point, int> p2) {
  ll ret = ccw(V[0].first, p1.first, p2.first);

  if (ret) {
    return ccw(V[0].first, p1.first, p2.first) > 0;
  }

  return dist(V[0].first, p2.first) - dist(V[0].first, p1.first) > 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int c;
  cin >> c;

  while (c--) {
    V.clear();

    int N;
    cin >> N;

    V.resize(N);

    for (int i = 0; i < N; i++) {
      ll x, y;
      cin >> x >> y;

      V[i] = {{x, y}, i};
    }

    swap(V[0], *min_element(V.begin(), V.end()));

    sort(V.begin() + 1, V.end(), compare);

    int idx = V.size() - 1;

    while (idx >= 1 && ccw(V[0].first, V[idx - 1].first, V[idx].first) == 0) {
      idx--;
    }

    reverse(V.begin() + idx, V.end());

    for (int i = 0; i < V.size(); i++) {
      cout << V[i].second << " ";
    }

    cout << "\n";
  }

  return 0;
}