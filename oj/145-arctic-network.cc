//
// 145 Arctic Network
// POJ-2349 ZOJ-1914 UVA-10369
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

struct point
{
    int x, y;
} po[505];
struct edge
{
    int u, v;
    double w;
};

int t, n, s, p[505]; // p - disjoint set
double res;
std::vector<point> u;
std::vector<edge> v;

int find(int x)
{
    return p[x] == -1 ? x : p[x] = find( p[x] );
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
double dist(point a, point b)
{
    double d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return std::sqrt(d);
}
double kruskal()
{
    double ans = 0;
    int cnt = 0;
    for (auto i: v)
    {
        int a = find( i.u ), b = find( i.v );

        if ( a != b )
        {
            ans = i.w;
            p[a] = b;
            cnt++;
        }
        if ( cnt == n-s ) break;
    }
    return ans;
}

int main()
{
    while( ~scanf("%d", &t) )
    {
        while ( t-- )
        {
            scanf("%d%d", &s, &n);
            for (int i=0; i<=n; ++i)
                p[i] = -1;

            for (int i=0; i<n; ++i)
                scanf("%d%d", &po[i].x, &po[i].y);

            for (int i=0; i<n; ++i)
                for (int j=i+1; j<n; ++j)
                    v.push_back( { i, j, dist( po[i], po[j] ) } );

            std::sort( v.begin(), v.end(), cmp );

            printf("%.2f\n", kruskal() );
            v.clear();
        }
    }
    return 0;
}
