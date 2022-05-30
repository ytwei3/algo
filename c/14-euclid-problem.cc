//
// 14 - Euclid Problem
//
//#include <stdio.h>
#include <iostream>
#include <array>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
#include <cmath>
#define endl "\n"
#define ll long long
using namespace std;

// Extended Euclid algo
ll gcd(ll p, ll q, ll *x, ll *y)
{
    ll m, n, g;

    if ( q > p )
        return gcd(q, p , y, x);

    if ( q == 0 )
    {
        *x = 1;
        *y = 0;
        return p;
    }

    g = gcd(q, p % q, &m, &n);

    *x = n;
    *y = ( m - floor(p/q)*n );

    return g;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, x, y, d;
    while ( cin >> a >> b )
    {
        d = gcd(a, b, &x, &y);

        cout << x << " " << y
             << " " << d << endl;
    }

    return 0;
}
