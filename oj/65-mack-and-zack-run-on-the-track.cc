//
// 65 - Mack and Zack Run on the Track
// 
// # fuck you!! iostream
//#include <stdio.h>
#include <iostream>
#include <iomanip>
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

            ml = 2*m*l + 2*pi*r1*m;
            zl = 2*z*l + 2*pi*r2*z;

            cout << "Track #" << n;
            if ( ml < zl )
                cout << ": I've run " << lrint(zl-ml)
                     << " more meters than Mack!!!" << endl;
            else
                cout << ": Drats!" << endl;
            n++;
        }
    }
    return 0;
}
