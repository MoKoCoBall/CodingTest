#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  int row = 1;
  cin >> N;
  while(N > row) {
    N -= row;
    row++;
  }
  if(row%2 == 0) cout << N << "/" << row + 1 - N;
  else cout << row + 1 - N << "/" << N;
  return 0;
}