//
/* 115 the 3n+1 problem (uva 100) */
//
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 1000000
using namespace std;

char buf[25];
int ar[maxn+1];
queue<int> q;

void bfs()
{
    int cur, u, v;
    q.push(1);
    ar[1] = 1;

    while ( !q.empty() )
    {
        cur = q.front();
        q.pop();

        u = cur*2, v = 3*cur + 1;
        if ( !ar[u] && u <= maxn )
            q.push(u), ar[u] = ar[cur] + 1;

        if ( !ar[v] && v <= maxn )
            q.push(v), ar[v] = ar[cur] + 1;
    }
}

int main ()
{
    for (int i=1; i<=maxn; i++)
        ar[i] = 0;

    bfs();

    int a, b, res;
    while ( fgets(buf, sizeof(buf), stdin) )
    {
        fputs(buf, stdout);
        sscanf(buf, "%d%d", &a, &b);

        res = -1;
        for (int i= min(a, b); i<=max(a, b); i++)
            res = max( ar[i], res );

        printf(" %d\n", res);
    }

    return 0;
}

