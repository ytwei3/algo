//
/* 507 - Zodiac Fever */
//
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int r, en, cor, trap, initPos, trPos, openPos;
int vis[1001][13];
long long dis[1001][13];
const int INF = 0x3f3f3f3f;
vector< pair<int, long long> > ar[1001];
unordered_map<int, pair<char, int> > m;

void init ()
{
    for (int i=1; i<=r; i++)
        ar[i].clear();
    m.clear();

    for (int i=1; i<=r; i++)
        for (int j=1; j<=12; j++)
            vis[i][j] = 0, dis[i][j] = INF;

    int a, b;
    long long d;
    char op;
    while ( cor-- )
    {
        scanf("%d%d%lld", &a, &b, &d);
        ar[a].push_back( { b, d } );
        ar[b].push_back( { a, d } );
    }

    while ( trap-- )
    {
        scanf("%d %c%d", &a, &op, &b);
        m[a] = { op, b };
    }
}
int operatrion(int status, pair<char, int> p)
{
    if (p.first == '+')
        status += p.second;
    else if ( p.first == '-' )
        status -= p.second;
    else if ( p.first == '*' )
        status *= p.second;
    else
        status = p.second;

    if ( status > 12 )
        status = status % 12;
    else
        while( status < 1 )
            status += 12;

    return status;
}
void floyd()
{

}


int main ()
{
    while ( ~scanf("%d%d%d%d%d%d%d", &r, &cor, &trap,
                &en, &initPos, &trPos, &openPos) )
    {
        init();

        floyd();

        dis[trPos][openPos] == INF ? puts("Pray!") : printf("%lld\n", dis[trPos][openPos]);
    }
    return 0;
}


