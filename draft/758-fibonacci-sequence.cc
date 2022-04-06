//
// My sample file
//
//#include <stdio.h>
#include <iostream>
//#include <array>
//#include <string>
#include <vector>
//#include <unoredered_map>
#include <algorithm>
//#include <cmath>
#define endl "\n"
using namespace std;

int t, n; 
long long q, sum, ar[5000000];
vector<long long> v;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    ar[0] = 1, ar[1] = 1;
    for (int i=2; i<5000000; ++i)
        ar[i] = ar[i-1] + ar[i-2];
    long long res = ar[5000000-1] % 100000000;

    cout << res << endl;

//    while ( cin >> t )
//    {
//        while ( t-- )
//        {
//            cin >> n >> q;
//
//            for (int i=1; i<=n; ++i)
//                v.push_back( ar[i] % q );
//
//            sort(v.begin(), v.end());
//
//            sum = 0;
//            for (int i=0; i<n; ++i)
//                sum += (i+1) * v[i];
//
//            cout << sum % q << endl;
//            v.clear();
//        }
//    }

    return 0;
}
