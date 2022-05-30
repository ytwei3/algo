//
// 168 - Networking
//
#include <stdio.h>
#include <vector>
#include <algorithm>

struct edge
{
    int u, v, w; // src, terminal, weight
};

int t, r;
int p[55];
std::vector<edge> v;

// have problem in recursion!
int find(int x)
{
    return p[x] == -1 ? x : p[x] = find( p[x] );
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int kruskal()
{
    int node = 0, sum = 0;
    for (auto i : v)
    {
        int a = find(i.u), b = find(i.v);
        if ( a != b )
        {
            sum += i.w;
            p[a] = b; // union
            node++;
        }
        if ( node == t-1 ) break;
    }
    return sum;
}


int main()
{
    while( scanf("%d", &t) && t )
    {
        scanf("%d", &r);
        for (int i=0; i<=t; ++i)
            p[i] = -1;

        edge e;
        for (int i=0; i<r; ++i)
        {
            scanf("%d%d%d", &e.u, &e.v, &e.w);
            v.push_back(e);
        }

        std::sort(v.begin(), v.end(), cmp );

        printf("%d\n", kruskal() );
        v.clear();
    }
    return 0;
}
