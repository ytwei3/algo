//
// 685 - Convex Quadrangles
//
//#include <stdio.h>
#include <iostream>
#include <array>
//#include <string>
#include <vector>
//#include <unoredered_map>
#include <algorithm>
#include <math.h>
#define pi acos(-1)
#define endl "\n"
using namespace std;

struct point
{
    double x, y;
};

int t, n, pos, cnt;
vector<point> p;
vector<double> a;

double an(double a, double b)
{
    double t = b-a;
    return ( t >= 0 ) ? t : t += 2*pi;
}
long long count()
{
    long long ans1 = n*(n-1)*(n-2)*(n-3)/24; // C(n, 4)
    for (int k=0; k<n; ++k)
    {
        for (int i=0; i<n; ++i)
            if ( k != i )
            {
                double angle = atan2(p[i].y-p[k].y, p[i].x - p[k].y);
                a.push_back(angle);
            }
        sort(a.begin(), a.end());
        long long ans2 = (n-1)*(n-2)*(n-3)/6;
        for (int i=0, j=0; i<a.size(); ++i)
        {
            while ( j < i+n-1 )
            {
                if ( an(a[i], a[j%(n-1)]) > pi )
                    break;
                j++;
            }
            ans2 -= ( j-i-1 ) * ( j-i-2 )/2;
        }
        ans1 -= ans2;
    }
    return ans1;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
    {
        while ( t-- )
        {
            cin >> n;
            for (int i=0; i<n; ++i)
            {
                double x, y;
                cin >> x >> y;
                p.push_back( { x, y } );
            }
            cout << count() << endl;
            p.clear(), a.clear();
        }
    }
    return 0;
}
