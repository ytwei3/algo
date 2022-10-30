//
/* 685 - Convex Quadrangles */
//
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
using namespace std;

struct point
{
    double x, y;
} p[701];

int n;
double const pi = acos(-1.0);
double a[1401];
long long s, c;

double getAngle(point a, point b)
{
    return atan2(b.y - a.y, b.x-a.x);
}
long long C(int n, int m)
{
    long long res = 1;
    for (int i=0; i<m; ++i)
        res = res * (n-i) / (i+1);
    return res;
}
long long solve()
{
    long long tol = 0;
    for (int i=0; i<n; ++i)
    {
        int cnt = 0;
        long long an = 0;
        for (int j=0; j<n; ++j)
            if ( i != j )
                a[cnt++] = getAngle( p[i], p[j] );

        sort( a, a + n - 1 );

        for (int j=0; j<n-1; j++)
            a[j+n-1] = a[j] + 2 * pi;

        for (int j=0, k=0; j<n-1; j++)
        {
            while ( a[j] + pi > a[k] )
                k++;
            an += C(k-j-1, 2);
        }
        tol += c - an;
    }
    return s - tol;
}

int main()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d", &n);
        c = C(n-1, 3);
        s = c * n/4;
        for (int i=0; i<n; ++i)
            scanf("%lf%lf", &p[i].x, &p[i].y);

        printf("%lld\n", solve() );
    }
    return 0;
}
