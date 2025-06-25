#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll D, P, Q;
  cin >> D >> P >> Q;

  if (Q > P) {
    swap(P, Q);
  }

  ll mn = ((D + P - 1) / P) * P;

  for (ll i = 0; i < Q; i++) {
    if (i * P >= D) {
      mn = min(mn, i * P);
      break;
    }

    ll tmp = i * P + ((D - i * P + Q - 1) / Q) * Q;
    mn = min(mn, tmp);

    if (mn == D) {
      break;
    }
  }

  cout << mn;

  return 0;
}