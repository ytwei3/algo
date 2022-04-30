#include <bits/stdc++.h>
using namespace std;

int q, m, cnt;

void solve()
{
    cnt = 0;
    while (true)
    {
        if (m < 2 || q * 100 + m * 10 < 220)
            break;
        if (cnt == 0)
        {
            if (q >= 2)
            {
                q -= 2, m -= 2;
            }
            else if (q == 1)
            {
                q -= 1, m -= 12;
            }
            else if (q == 0)
                m -= 22;
        }
        else
        {
            if (m >= 22)
                m -= 22;
            else if (m >= 12)
            {
                q -= 1, m -= 12;
            }
            else if (m >= 2)
            {
                q -= 2, m -= 2;
            }
        }
        cnt = 1 - cnt;
    }
    cout << ((!cnt) ? "Kengood\n" : "Bert\n");

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> q >> m)
    {
        solve();
    }
}
