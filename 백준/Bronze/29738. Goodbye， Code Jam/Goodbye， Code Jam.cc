#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int N;
        cin >> N;

        cout << "Case #" << i << ": ";

        if (N > 4500)
        {
            cout << "Round 1\n";
        }
        else if (N > 1000)
        {
            cout << "Round 2\n";
        }
        else if (N > 25)
        {
            cout << "Round 3\n";
        }
        else
        {
            cout << "World Finals\n";
        }
    }

    return 0;
}