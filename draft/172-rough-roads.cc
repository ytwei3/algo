//
/* 172 - Rough Roads */
//
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int u, w, s;
    int operator < ( const edge &e ) const
    {
        return w > e.w; // reverse order
    }
};

int n, r, vis[505][2], dis[505][2];
const int INF = 0x3f3f3f3f;

vector< pair<int, int> > ar[505];

void init()
{
    for (int i=0; i<n; i++)
        ar[i].clear();

    for (int i=0; i<n; i++)
        for (int j=0; j<2; j++)
            vis[i][j] = 0, dis[i][j] = INF;
    dis[0][1] = 0;

    int a, b, d;
    while ( r-- )
    {
        scanf("%d%d%d", &a, &b, &d);
        ar[a].push_back( { b, d } );
        ar[b].push_back( { a, d } );
    }
}
void dijkstra()
{
    priority_queue<edge> q;
    q.push( { 0, 0, 1 } );

    while ( !q.empty() )
    {
        edge e = q.top();
        q.pop();

        if ( !vis[e.u][e.s] )
        {
            int ns =! e.s;
            vis[e.u][e.s] = 1;
            for (auto i : ar[e.u])
            {
                int weight = dis[e.u][e.s] + i.second;
                if (  weight < dis[i.first][ns] )
                {
                    dis[i.first][ns] = weight;
                    q.push( { i.first, weight, ns } );
                }
            }
        }
    }
}

int main ()
{
    int set = 1;
    while ( ~scanf("%d%d", &n, &r) )
    {
        init();

        dijkstra();

        printf("Set #%d\n", set++);
        dis[n-1][1] == INF ? puts("?") : printf("%d\n", dis[n-1][1]);
    }
    return 0;
}
