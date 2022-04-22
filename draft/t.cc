#include"stdio.h"
#include"string.h"
#include"iostream"
#define M 111
#define inf 99999999
#define eps 1e-9
#include"math.h"
using namespace std;
int G[M][M],dis[M][M],path[M][M],n,b[M];
void floyd()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dis[i][j]=G[i][j];
            path[i][j]=j;
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j]+b[k])
                {
                    dis[i][j]=dis[i][k]+dis[k][j]+b[k];
                    path[i][j]=path[i][k];
                }
                else if(dis[i][j]==dis[i][k]+dis[k][j]+b[k])
                {
                    if(path[i][j]>path[i][k]&&i!=k)
                        path[i][j]=path[i][k];
                }
            }
        }
    }
}
void solve(int i,int j)
{
    printf("From %d to %d :\n",i,j);
    printf("Path: ");
    int k=i;
    printf("%d",i);
    while(k!=j)
    {
        printf("-->%d",path[k][j]);
        k=path[k][j];
    }
    printf("\n");
    printf("Total cost : %d\n\n",dis[i][j]);
}
int main()
{
    int i,j;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                G[i][j]=inf;
            }
            G[i][i]=0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                int a;
                scanf("%d",&a);
                if(a!=-1)
                    G[i][j]=a;
            }
        }
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d", dis[i][j]);
            puts("");
        }
    }
    return 0;
}
