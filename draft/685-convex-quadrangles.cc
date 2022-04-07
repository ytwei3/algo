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
    long long x, y;
};

int t, n, pos, cnt;
const int INF =0x3f3f3f3f;
vector<point> p;
vector<double> a;

double angle(double a, double b)
{
    double t = b-a;
    return ( t >= 0 ) ? t : t += 2*pi;
}

int cmp(point a, point b)
{
    return (cross(p0, a, b) > 0 || ( cross(p0, a, b) == 0 && dis(p0, a) <= dis(p0, b) )) ? 1 : 0;
}

long long count()
{
    long long quad = n*(n-1)*(n-2)*(n-3)/24; // C(n, 4)
    for (int i=0; i<n; ++i)
    {
        int cnt = 0;
        for (int i=0; i<n; ++i)
    }

    return quad;
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
                int x, y;
                cin >> x >> y;
                p.push_back( { x, y } );
            }
            cout << count() << endl;
            p.clear(), a.clear();
        }
    }
    return 0;
}
