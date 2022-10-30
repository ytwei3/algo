// 
// 126 - Risk
//
// #floyd algo
#include <stdio.h>

const int INF = 0x3f3f3f3f;

int adjMatrix[23][23];
int n, node, s, t;
int src, des;

void init()
{
    for (int i=0; i<=20; ++i)
        for(int j=0; j<=20; ++j)
            adjMatrix[i][j] = INF;

    for (int i=0; i<=20; ++i)
        adjMatrix[i][i] = 0;
}
void input()
{
    for (int i=1; i<=n; ++i)
    {
        scanf("%d", &node);
        adjMatrix[1][node] = adjMatrix[node][1] = 1;
    }

    for (int i=2; i<=19; ++i)
    {
        scanf("%d", &n);
        for (int j=1; j<=n; ++j)
        {
            scanf("%d", &node);
            adjMatrix[i][node] = adjMatrix[node][i] = 1;
        }
    }
}
void floyd()
{
    for (int k=1; k <= 20; ++k)
        for (int i=1; i <= 20; ++i)
            for (int j=1; j <= 20; ++j)
                if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
}
void test()
{
    printf("Test Set #%d\n", t++);
    scanf("%d", &s);
    for (int i=0; i<s; ++i)
    {
        scanf("%d%d", &src, &des);
        printf("%2d to %2d: %d\n", src, des, adjMatrix[src][des]);
    }
    printf("\n");
}

int main ()
{
    t = 1;
    while ( ~scanf("%d", &n) )
    {
        init();
        input();
        floyd();
        test();
    }
    return 0;
}
