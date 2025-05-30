#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  long double Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;

  for (int i = 0; i < N; i++) {
    long double a, b;
    cin >> a >> b;

    Sx += a;
    Sy += b;
    Sxx += a * a;
    Sxy += a * b;
  }

  if (N * Sxx == Sx * Sx) {
    cout << "EZPZ";
  } else {
    long double A = (N * Sxy - Sx * Sy) / (N * Sxx - Sx * Sx);
    long double B = (Sy - A * Sx) / N;

    cout << fixed << setprecision(16) << A << " " << B;
  }

  return 0;
}