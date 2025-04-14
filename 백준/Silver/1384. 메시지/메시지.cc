#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int num = 1;

  while (1) {
    cin >> N;
    if (N == 0) {
      return 0;
    }

    vector<string> V(N);
    vector<vector<char>> message(N, vector<char>(N - 1));

    for (int i = 0; i < N; i++) {
      cin >> V[i];
      for (int j = 0; j < N - 1; j++) {
        cin >> message[i][j];
      }
    }

    bool flag = false;

    cout << "Group " << num << "\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N - 1; j++) {
        int idx = (N + i - j - 1) % N;

        if (message[i][j] == 'N') {
          cout << V[idx] << " was nasty about " << V[i] << "\n";
          flag = true;
        }
      }
    }

    if (!flag) {
      cout << "Nobody was nasty" << "\n";
    }

    cout << "\n";
    num++;
  }

  return 0;
}