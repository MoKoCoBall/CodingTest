#include <bits/stdc++.h>

using namespace std;

int compare(char c) {
  if (c == '(') return 0;
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string exp;
  cin >> exp;

  stack<char> S;

  for (char c : exp) {
    if (c >= 'A' && c <= 'Z') {
      cout << c;
    } else if (c == '(') {
      S.push(c);
    } else if (c == ')') {
      while (S.top() != '(') {
        cout << S.top();
        S.pop();
      }
      S.pop();
    } else {
      while (!S.empty() && compare(S.top()) >= compare(c)) {
        cout << S.top();
        S.pop();
      }
      S.push(c);
    }
  }

  while (!S.empty()) {
    cout << S.top();
    S.pop();
  }

  return 0;
}