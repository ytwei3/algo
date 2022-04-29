//
/* 396 - Dual Core */
//
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 20001
#define maxm 20001
using namespace std;


struct edge
{
    int from, to, cap, flow;
};

int n, m, s, t, tol;
int head[maxn], ver[maxm], nx[maxm], edge[maxm], d[maxn];
const int INF = 0x3f3f3f3f;

void add(int u, int v, int w)
{
    ver[++tol] = v;
    edge[tol] = w;
    nx[tol] = head[u];
    head[u] = tol;

    ver[++tol] = u;
    edge[tol] = 0;
    nx[tol] = head[v];
    head[v] = tol;
}
void init()
{
    s = 0, t = n + 1, tol = 1;

    for (int i=0; i<=maxn; i++)
        head[i] = nx[i] = 0;

    int a, b, c;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a, &b);
        add(s, i, a);
        add(i, t, b);
    }

    for (int i=0; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

}
int bfs()
{
    for (int i=0; i<=maxn; i++)
        d[i] = 0;

    queue<int> q;
    q.push(s);
    d[s] = 1;

    while ( !q.empty() )
    {
        int x = q.front();
        q.pop();

        for (int i=head[x]; i ; i = nx[i])
        {
            if ( edge[i] && !d[ ver[i] ] )
            {
                q.push( ver[i] );
                d[ ver[i] ] = d[x] + 1;

                if ( ver[i] == t )
                    return 1;
            }
        }
    }
    return 0;
}
int dfs(int x, int a)
{
    if ( x == t || !a )
        return a;

    int flow = 0;
    for (int i = head[x]; i ; i = nx[i])
    {
        if ( edge[i] && d[ ver[i] ] == d[x] + 1 )
        {
            int k = dfs( ver[i], min( a - flow, edge[i]) );
            edge[i] -= k;
            edge[i^1] += k;
            flow += k;

            if ( flow == a )
                return flow;
        }
    }
    if ( !flow )
        d[x] = 0;
    return flow;
}
int dinic()
{
    int maxflow = 0;
    while ( bfs() )
        maxflow += dfs( s, INF );

    return maxflow;
}

int main ()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        init();

        printf("%d\n", dinic() );
    }
    return 0;
}

