//
// A -
//
#include <stdio.h>
//#include <iostream>
//#include <array>
//#include <string>
#include <vector>
//#include <unordered_map>
#include <algorithm>
//#include <cmath>
#define endl "\n"
#define ll long long
//ios::sync_with_stdio(false);
//cin.tie(nullptr);
using namespace std;

int n, ar[51], d[51];

int main()
{
    while ( ~scanf("%d", &n) )
    {
        for (int i=0; i<n; ++i)
            ar[i] = 0;

        for (int i=0; i<n; ++i)
            scanf("%d", &ar[i]);
        
        sort(ar, ar+n);

        int h = n/2;
        for (int i=0, j=n-1; i<h; ++i, --j)
            d[i] = ar[i] + ar[j];

        sort(d, d+h);
        printf("%d\n", d[h-1] - d[0]);
    }
    return 0;
}
