//
/* 651 - Best Sum */
//
#include <cstdio>
#include <algorithm>
#define maxn 10000
using namespace std;

struct point
{
    int x, y;
}
ab[maxn+1], ar[maxn+1];

int n, m;
int x[maxn+1], y[maxn+1];
point p[maxn+1], h[maxn+1];


int cmp(point a, point b)
{
    return a.x < b.x || ( a.x == b.x && a.y < b.y );
}
long long cross(point a, point b, point c)
{
    return 1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(c.x-a.x)*(b.y-a.y);
}
void init()
{
    m = 1;
    x[0] = y[0] = 0;

    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &ab[i].x);

    for (int i=0; i<n; i++)
        scanf("%d", &ab[i].y);
}
void convexhull()
{
    int k = 0;
    sort(p, p+m, cmp);

    for (int i=0; i<m; i++)
    {
        while ( k >=2 && cross(h[k-2], h[k-1], p[i]) <= 0 )
            k--;
        h[k++] = p[i] ;
    }

    for (int i=m-2, t=k+1; i>=0; i--)
    {
        while ( k >=t && cross(h[k-2], h[k-1], p[i]) <= 0 )
            k--;
        h[k++] = p[i] ;
    }

    m = k-1;

}
void solve()
{

    for (int i=0, k; i<n; i++)
    {
        k = m;
        for (int j=0; j<k; j++)
        {
            x[m] = x[j] + ab[i].x;
            y[m++] = y[j] + ab[i].y;
        }
        if ( m <= 2 )
            continue;

        for (int j=0; j<m; j++)
        {
            ar[j].x = p[j].x = x[j];
            ar[j].y = p[j].y = y[j];
        }

        convexhull();

        for (int i=0; i<m; i++)
        {
            x[i] = h[i].x;
            y[i] = h[i].y;
        }
    }
}
long long getRes()
{
    long long res = 0;
    for (int i=0; i<m; i++)
        res = max(res, 1LL*x[i]*x[i] + 1LL*y[i]*y[i]);
    return res;
}

int main ()
{
    int t;
    scanf("%d", &t);

    while ( t-- )
    {
        init();

        solve();

        printf("%lld\n", getRes() );
    }
    return 0;
}

