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

  int T;
  cin >> T;

  while (T--) {
    V.clear();
    vector<Point> hull;
    stack<Point> S;

    int N;
    cin >> N;

    V.resize(N);

    for (int i = 0; i < N; i++) {
      ll x, y;
      cin >> x >> y;

      V[i] = {x, y};
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

        if (ccw(p1, p2, V[i]) > 0) {
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

    ll ans = 0;
    Point p1, p2;
    int j = 1;

    for (int i = 0; i < hull.size(); i++) {
      int ni = (i + 1) % hull.size();

      while (true) {
        int nj = (j + 1) % hull.size();
        Point pi, pj;

        pi.x = hull[ni].x - hull[i].x;
        pi.y = hull[ni].y - hull[i].y;
        pj.x = hull[nj].x - hull[j].x;
        pj.y = hull[nj].y - hull[j].y;

        if (ccw(Point({0, 0}), pi, pj) > 0) {
          j = nj;
        } else {
          break;
        }
      }

      ll d = dist(hull[i], hull[j]);

      if (d > ans) {
        ans = d;
        p1 = hull[i];
        p2 = hull[j];
      }
    }

    cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << "\n";
  }

  return 0;
}