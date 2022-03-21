// 126 - Risk
//
//
#include <stdio.h>
#include <vector>

const int INF = 0x3f3f3f3f;
const int N = 22;

std::vector<int> adjList[1001];
int adjMatrix[N][N];
int ans;

int main ()
{

    for (int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            if (i == j)
                adjMatrix[i][j] = 0;
            else
                adjMatrix[i][j] = INF;

    int n, node;
    for (int i=1; i<=19; ++i)
    {
        scanf("%d", &n);
        for (int j=0; j<n; ++j)
        {
            scanf("%d", &node);
            adjMatrix[i][node] = 1;
            adjMatrix[node][i] = 1;
        }
    }

    for (int k=0; k < N; ++k)
        for (int i=0; i < N; ++i)
            for (int j=0; j < N; ++j)
                if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];

    printf("%d", ans);



    return 0;
}
