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

int room, corridor, trap, entrance;
int initial_ring_position, treasure_room, open_ring_position;
int dis[1001][13], vis[1001][13];
const int INF = 0x3f3f3f3f;
vector< pair<int, int> > ar[1001];
unordered_map<int, tr> map;

void init ()
{
    for (int i=1; i<=room; i++)
        ar[i].clear();

    for (int i=1; i<=room; i++)
        for (int j=1; j<=12; j++)
            vis[i][j] = 0, dis[i][j] = INF;

    map.clear();

    int a, b, c;
    char op;
    for (int i=0; i<corridor; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        ar[a].push_back( { b, c } );
        ar[b].push_back( { a, c } );
    }

    for (int i=0; i<trap; i++)
    {
        scanf("%d%c%d", &a, &op, &b);
        map[a] = { op, b };
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
int operatrion(int where, int status, tr p)
{
    int ns; // now status
    if (p.op == '+')
        ns = status + p.n;
    else if ( p.op == '-' )
        ns = status - p.n;
    else if ( p.op == '*' )
        ns = status - p.n;
    else
        ns = p.n;

    return check(ns);
}
void dijkstra()
{
    priority_queue<edge> q;
    int status = operatrion(entrance, initial_ring_position, map[entrance]);
    if ( map.count( entrance ) )
        dis[entrance][ status ] = 0;
    q.push({ entrance, 0, status });

    while ( !q.empty() )
    {
        edge e = q.top();
        q.pop();

        if ( !vis[e.u][e.s] )
        {
            int ns;
            if ( map.count(e.u) )
                ns = operatrion(e.u, e.s, map[e.u]);
            else
                ns = e.s;

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

