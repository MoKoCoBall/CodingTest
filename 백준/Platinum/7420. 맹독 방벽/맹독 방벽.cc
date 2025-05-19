#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double PI = 3.1415926535;

struct Point {
  ll x, y;

  bool operator<(const Point& p) const {
    if (y != p.y) return y < p.y;
    return x < p.x;
  }
};

vector<Point> V;

ll ccw(Point p1, Point p2, Point p3) {
  return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
         (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

bool compare(Point p1, Point p2) {
  ll ret = ccw(V[0], p1, p2);

  if (ret > 0) {
    return true;
  } else if (ret < 0) {
    return false;
  } else {
    if (p1.y != p2.y) {
      return p1.y < p2.y;
    } else {
      return p1.x < p2.x;
    }
  }
}

ll dist(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, L;
  cin >> N >> L;

  vector<Point> hull;
  stack<Point> S;

  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;

    V.push_back({x, y});
  }

  swap(V[0], *min_element(V.begin(), V.end()));

  sort(V.begin() + 1, V.end(), compare);

  S.push(V[0]);
  S.push(V[1]);

  for (int i = 2; i < N; i++) {
    while (S.size() >= 2) {
      Point p2 = S.top();
      S.pop();

      Point p1 = S.top();

      if (ccw(p1, p2, V[i]) >= 0) {
        S.push(p2);
        break;
      }
    }

    S.push(V[i]);
  }

  while (!S.empty()) {
    hull.push_back(S.top());
    S.pop();
  }

  reverse(hull.begin(), hull.end());

  double ans = 2 * PI * L;

  for (int i = 0; i < hull.size() - 1; i++) {
    ans += sqrt(dist(hull[i], hull[i + 1]));
  }

  ans += sqrt(dist(hull[hull.size() - 1], hull[0]));

  cout << fixed << setprecision(0) << ans;

  return 0;
}