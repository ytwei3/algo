// 821 - Distance 
//
// #adjency List implementation #dfs
//
// The Longest path in a tree is the 
// Sum of the Longest path and 
// the second Longest path
// from the root node. 
#include <cstdio>
#include <vector>
#define maxn 100000

struct edge
{
	int v;
	long long w;
};

std::vector<edge> ar[maxn+1]; // 1 <= n <= 10^5
int vis[maxn+1];

int maxNode, n;
long long maxD;

void dfs(int node, long long dist)
{
    vis[node] = 1;

    if (dist > maxD)
        maxD = dist, maxNode = node;

    for ( auto i : ar[node] )
        if ( !vis[i.v] )
            dfs(i.v, dist + i.w);
}

int main ()
{
    scanf("%d", &n);

    int u, v;
    long long w;

    for (int i=1; i<n; i++)
    {
        scanf("%d%d%lld", &u, &v, &w);
        ar[u].push_back( { v, w } );
        ar[v].push_back( { u, w } );
    }

    maxD = -1;
    for (int i=1; i<=n; ++i)
        vis[i] = 0;
    dfs(1, 0);

    maxD = -1;
    for (int i=1; i<=n; ++i)
        vis[i] = 0;
    dfs(maxNode, 0);

    printf("%lld\n", maxD);

    return 0;
}
