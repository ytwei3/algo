//
/* 172 - Rough Roads */
//
#include <stdio.h>
#include <vector>
using namespace std;

struct edge
{
    int v, w;
};

int n, r, vis[501], d[501];
const int INF = 0x3f3f3f3f;
vector<edge> ar[501];

int main ()
{
    int a, b, d, set = 1;
    while ( ~scanf("%d%d", &n, &r) )
    {
        for (int i=0; i<=n; i++)
            vis[i] = 0, d = INF;
        vis[0] = 1, d[0] = 0; 


        int a, b, d;
        while ( r-- )
        {
            scanf("%d%d%d", &a, &b, &d);
            ar[a].push_back( { b, d } );
            ar[b].push_back( { a, d } );
        }

        printf("Set #%d\n%d", set, dis);
    }
    return 0;
}

