#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000003;

// 행렬 정의
struct Matrix {
  vector<vector<ll>> V;
  int size;

  Matrix(int N) {
    size = N;
    V = vector<vector<ll>>(N, vector<ll>(N));
  }

  Matrix operator*(const Matrix &m) {
    Matrix ret(size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
          ret.V[i][j] += V[i][k] * m.V[k][j];
          ret.V[i][j] %= mod;
        }
      }
    }

    return ret;
  }
};

Matrix matpow(Matrix &a, ll b) {
  if (b == 1) {
    return a;
  }

  Matrix ret = matpow(a, b / 2);
  ret = ret * ret;

  if (b % 2) {
    ret = ret * a;
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, S, E, T;
  cin >> N >> S >> E >> T;
  S--;
  E--;

  Matrix matrix(N * 5 + 1);

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < 5; j++) {
      matrix.V[i * 5 + j][i * 5 + j - 1] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;

    for (int j = 0; j < S.size(); j++) {
      int tmp = S[j] - '0';

      if (tmp >= 1) {
        matrix.V[i * 5][j * 5 + tmp - 1] = 1;
      }
    }
  }

  matrix = matpow(matrix, T);

  cout << matrix.V[S * 5][E * 5];

  return 0;
}