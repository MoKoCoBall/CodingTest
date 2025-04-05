#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> V(N);

  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }

  if (N == 1) {
    cout << "A";
    return 0;
  } else if (N == 2) {
    if (V[0] == V[1]) {
      cout << V[0];
      return 0;
    } else {
      cout << "A";
      return 0;
    }
  } else {
    int a = V[1] - V[0] == 0 ? 0 : (V[2] - V[1]) / (V[1] - V[0]);
    int b = V[1] - V[0] * a;

    for (int i = 0; i < N - 1; i++) {
      if (V[i + 1] != V[i] * a + b) {
        cout << "B";
        return 0;
      }
    }

    cout << V[N - 1] * a + b;
  }

  return 0;
}