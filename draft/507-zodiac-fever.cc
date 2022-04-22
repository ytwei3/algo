//
/* 507 - Zodiac Fever */
//
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct edge
{
    int u, w, s;
    int operator < ( const edge &e ) const
    {
        return w > e.w;
    }
};
struct tr
{
    char op;
    int n;
};

int r, c, t, en;
int initial_ring_position, treasure_room, open_ring_position;
int dis[1001][13], vis[1001][13];
const int INF = 0x3f3f3f3f;
vector< pair<int, int> > ar[1001];
tr oper[1001];

void init ()
{
    for (int i=1; i<=r; i++)
        ar[i].clear(), oper[i] = { 0, -1 };

    for (int i=1; i<=r; i++)
        for (int j=0; j<=12; j++)
            vis[i][j] = 0, dis[i][j] = INF;


    int a, b, c;
    char op;
    for (int i=0; i<c; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        ar[a].push_back( { b, c } );
        ar[b].push_back( { a, c } );
    }

    for (int i=0; i<t; i++)
    {
        scanf("%d%c%d", &a, &op, &b);
        oper[a] = { op, b };
    }
}
int check(int ns)
{
    if ( ns > 12 )
        ns = ns % 12;
    else if ( ns < 0 )
        ns += 12;
    return ns;
}
int operatrion(int status, tr p)
{
    if (p.op == '+')
        status += p.n;
    else if ( p.op == '-' )
        status -= p.n;
    else if ( p.op == '*' )
        status *= p.n;
    else
        return status;

    return check(status);
}
void dijkstra()
{
    int status = initial_ring_position;
    priority_queue<edge> q;

    if ( oper[entrance].n != -1 )
    {
        status = operatrion(initial_ring_position, oper[entrance]);
        dis[entrance][ status ] = 0;
    }
    q.push({ entrance, 0, status });

    while ( !q.empty() )
    {
        edge e = q.top();
        q.pop();

        printf("The value of this e is %d %d %d\n", e.u, e.w, e.s);

        if ( !vis[e.u][e.s] )
        {
            // ns - next status
            int ns;
            if ( oper[e.u].n != -1 )
                ns = operatrion(e.s, oper[e.u]);
            else
                ns = e.s;
            printf("The value of next status: %d", ns);

            vis[e.u][e.s] = 1;
            for ( auto i: ar[e.u] )
            {
                int weight = dis[e.u][e.s] + i.second;
                if ( weight < dis[i.first][ns] )
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
    while ( ~scanf("%d%d%d%d%d%d%d", &room, &corridor, &trap,
                &entrance, &initial_ring_position, &treasure_room, 
                &open_ring_position) )
    {
        init();

        dijkstra();

        dis[treasure_room][open_ring_position] == INF ? puts("Pary!") : printf("%d\n", dis[treasure_room][open_ring_position]);
    }
    return 0;
}

