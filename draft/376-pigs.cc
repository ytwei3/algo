//
/* 376 - pigs */
//
#include <cstdio>
#include <vector>
#include <queue>
#define maxm 1000
using namespace std;


struct edge
{
    int from, to, cap;
};

int n, m, s, t, tol;
int head[maxm+1], cur[maxm+1], d[maxm+1];
const int INF = 0x3f3f3f3f;

vector<edge> e;
vector<int> g[maxm+1];

void add(int from, int to, int cap)
{
    e.push_back({ from, to, cap });
    e.push_back({ to, from, 0 });

    int tol = e.size();
    g[from].push_back( tol-2 );
    g[to].push_back( tol-1 );
}
int bfs()
{
    for (int i=0; i<=maxm; i++)
        d[i] = -1;
    d[s] = 0;

    queue<int> q;
    q.push(s);

    while ( !q.empty() )
    {
        int x = q.front();
        q.pop();

        for (int i=0; i < g[x].size(); i++ )
        {
            edge& ed = e[ g[x][i] ];
            if ( d[ ed.to ] == -1 && ed.cap > 0 )
            {
                d[ ed.to ] = d[x] + 1;
                q.push( ed.to );
            }
        }
    }
    return d[t] != -1;
}
int dfs(int x, int a)
{
    if ( x == t || !a )
        return a;

    int flow = 0, f;
    for (int& i = cur[x]; i < g[x].size() ; i++ )
    {
        edge &ed = e[ g[x][i] ];
        if ( (f = dfs( ed.to, min( a, ed.cap) )) > 0 && d[ ed.to ] == d[x] + 1 )
        {
            ed.cap -= f;
            e[ g[x][i]^1 ].cap += f;
            flow += f;
            a -= f;

            if ( flow == 0 )
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
        for (int i=0; i<=maxm; i++)
            cur[i] = 0;

        maxflow += dfs( s, INF );
    }
    return maxflow;
}
void build()
{
    int a, b, c, pre[maxm+1], pig[maxm+1];
    for (int i=0; i<=maxm; i++)
        pre[i] = -1;

    for (int i=1; i<=m; i++)
        scanf("%d", &pig[i]);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        while ( a-- )
        {
            scanf("%d",&b);

            pre[b] == -1 ? add(s, i, pig[b])
                        : add(pre[b], i, INF);
            pre[b]= i;
        }
        scanf("%d",&c);
        add(i, t, c);
    }
    n+=2;
}

int main ()
{
    while ( ~scanf("%d%d", &m, &n) )
    {
        s = 0, t = n + 1, tol = 0;
        build();

        printf("%d\n", dinic() );
    }
    return 0;
}
