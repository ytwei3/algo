//
/* 396 - Dual Core */
//
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 20001
using namespace std;

struct edge
{
    int u, v, cap, flow;
};

int n, m, s, t, tol, maxflow;
int head[20001], ver[20001], nx[20001], edge[20001], d[20001];
const int INF = 0x3f3f3f3f;

void init()
{
    maxflow = 0, tol = 1;
    s = 0, t = n + 1;

    for (int i=0; i<n+1; i++)
        head[i] = nx[i] = 0;
}

int main ()
{
    int n, m, a, b, w;
    while ( ~scanf("%d%d", &n, &m) )
    {
        while ( n-- )
        {
            scanf("%d%d%d", &a, &b, &w);
        }
    }

    return 0;
}

