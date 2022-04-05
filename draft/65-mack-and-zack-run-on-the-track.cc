//
// 65 - Mack and Zack Run on the Track
//
//#include <stdio.h>
#include <iostream>
//#include <array>
//#include <string>
//#include <vector>
//#include <unoredered_map>
//#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;

int t, l, r1, r2, m, z, n;
double ml, zl;
double const pi = 3.141592653589793;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
    {
        n = 1;
        while ( t-- )
        {
            cin >> l >> r1 >> r2 >> m >> z;

            ml = 2*m*(l + pi*r1);
            zl = 2*z*(l + pi*r2);

            cout << "mack: " << ml << endl
                 << "zack: " << zl << endl;

            cout << "Track #" << n;
            if ( ml < zl )
                cout << ": I've run " << round(zl-ml)
                     << " more meters than Mack!!!" << endl;
            else
                cout << ": Drats!" << endl;
            n++;
        }
    }
    return 0;
}
