// 821 - Distance 
//
// #adjency List implementation #dfs
//
// The Longest path in a tree is the 
// Sum of the Longest path and 
// the second Longest path
// from the root node. 
#include <stdio.h>
#include <vector>

std::vector<int> aList[100001]; // 1 <= n <= 10^5
std::vector<long long> weight[100001];
int visit[100001];

int maxNode;
long long maxD;

void dfs(int node, long long dist)
{
    visit[node] = 1;

    if (dist > maxD)
    {
        maxD = dist;
        maxNode = node;
    }

    auto iter = weight[node].begin();
    for (auto i = aList[node].begin(); i != aList[node].end(); ++i)
    {
        if (visit[*i] == 0 )
            dfs(*i, dist + *iter);
        iter++;
    }
    
}
void buildGraph(int u, int v, long long d) 
{
    aList[u].push_back(v);
    aList[v].push_back(u);

    weight[u].push_back(d);
    weight[v].push_back(d);
}

int main ()
{
    int node;
    //printf("Please enter the node: ");
    scanf("%d", &node);
    //printf("Please enter the u, v, distance: \n");

    int u, v;
    long long d;
    while (node != 1 )
    {
        // Build graph (adjency List)
        scanf("%d %d %lld", &u, &v, &d);
        buildGraph(u, v, d);
        node--;
    }

    maxD = -1;
    dfs(1, 0);

    for (int i=0; i<100001; ++i)
        visit[i] = 0;

    maxD = -1;
    dfs(maxNode, 0);

    //printf("The Distance is: ");
    printf("%lld\n", maxD);

    return 0;
}
