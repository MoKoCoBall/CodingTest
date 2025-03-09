#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long KHP, KATK, MHP, MATK;
    cin >> KHP >> KATK >> MHP >> MATK;

    long long P, S;
    cin >> P >> S;

    long long ret = MHP % KATK == 0 ? KATK : MHP % KATK;

    long long Kturn;

    if (ret <= P)
    {
        long long tmp = (ret + S + KATK - 1) / KATK;

        Kturn = (MHP - ret) / KATK + tmp;
    }
    else
    {
        Kturn = (MHP + KATK - 1) / KATK;
    }

    long long Mturn = (KHP + MATK - 1) / MATK;

    if (Kturn <= Mturn)
    {
        cout << "Victory!";
    }
    else
    {
        cout << "gg";
    }

    return 0;
}