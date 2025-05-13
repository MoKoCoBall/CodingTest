#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct {
  ll x, y;
} Point;

vector<Point> V, hull;
stack<Point> S;

ll ccw(Point p1, Point p2, Point p3) {
  return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
         (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

// 좌표 반시계 정렬
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

long long dist(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;

    V.push_back({x, y});
  }

  // 1. 시작점을 y좌표가 최소인 값으로 정렬, y좌표 최솟값이 여러개라면 x좌표가
  // 최솟값인 점을 잡음
  // 2. 시작점 기준 반시계방향 정렬
  // 3. 스택에 시작점과 첫번째 점을 넣음
  // 4. 나머지 점을 스택에 넣음

  for (int i = 1; i < N; i++) {
    if (V[i].y < V[0].y || (V[i].y == V[0].y && V[i].x < V[0].x)) {
      swap(V[0], V[i]);
    }
  }

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

  long long ans = 0;
  int idx = 0;

  for (int i = 0; i < hull.size(); i++) {
    idx = (i + 1) % hull.size();

    while (idx != i &&
           ccw(hull[i], hull[idx], hull[(idx + 1) % hull.size()]) >= 0) {
      ans = max(ans, dist(hull[i], hull[idx]));
      idx = (idx + 1) % hull.size();
    }

    ans = max(ans, dist(hull[i], hull[idx]));
  }

  cout << fixed << setprecision(10) << sqrt(ans);

  return 0;
}