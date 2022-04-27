//
/* 396 - Dual Core */
//
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 201
#define maxm 2001
using namespace std;


struct edge
{
    int from, to, cap, flow;
};

int n, m, s, t;
int head[maxn], ver[maxm], nx[maxm], edge[maxm], d[maxn];
const int INF = 0x3f3f3f3f;

void init()
{
    s = 0, t = n + 1;

    for (int i=0; i<n; i++)
        g[i].clear();
    e.clear();
}
void add(int u, int v, int w)
{
    ver[++tol] = v, edge[tol] = z,
}
int bfs()
{
    for (int i=0; i<=n; i++)
        vis[i] = 0;

    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while ( !q.empty() )
    {
        int x = q.front();
        q.pop();
        for (int i=0; i<g[x].size(); i++)
        {
            edge ed = e[ g[x][i] ];
            if ( !vis[ed.to] && ed.cap > ed.flow )
            {
                vis[ed.to] = 1;
                d[ed.to] = d[x] + 1;
                q.push(ed.to);
            }
        }
    }
    return vis[t];
}
int dfs(int x, int a)
{
    if ( x == t || !a )
        return a;
    int flow = 0, f;
    for (int i = cur[x]; i < g[x].size(); i++)
    {
        edge ed = e[ g[x][i] ];
        if ( d[x] + 1 == d[ed.to] &&
                ( f = dfs(ed.to, min(a, ed.cap - ed.flow)) ) > 0)
        {
            ed.flow += f;
            e[ g[x][i]^1 ].flow -= f;
            flow += f;
            a -= f;
            if ( !a )
                break;
        }
    }
    return flow;
}
int dinic()
{
    int maxflow = 0;
    while ( bfs() )
    {
        for (int i=1; i<=n; i++)
            cur[i] = 0;

        maxflow += dfs( s, INF );
    }
    return maxflow;
}

int main ()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        init();

        int a, b, c;
        for (int i=1; i<=n; ++i)
        {
            scanf("%d%d", &a, &b);
            addEdge(s, i, a);
            addEdge(i, t, b);
        }

        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            addEdge(a, b, c);
            addEdge(b, a, c);
        }

        printf("%d\n", dinic() );
    }
    return 0;
}

