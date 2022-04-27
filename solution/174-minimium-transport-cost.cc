//
/* 174 - Minimium Transport Cost */
//
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, b, len;
int dis[1001][1001], nx[1001][1001], tax[1001];
const int INF = 0x3f3f3f3f;
char buf[11];

void init()
{
    len = 0;
    do
    {
        scanf("%d", &n);
        if ( n == -1 )
            dis[1][++len] = INF;
        else
            dis[1][++len] = n;
    } while ( getchar() != '\n');

    for (int i=2; i<=len; i++)
        for (int j=1; j<=len; j++)
        {
            scanf("%d", &n);
            if ( n == -1 )
                dis[i][j] = INF;
            else
                dis[i][j] = n;
        }

    for (int i=1; i<=len; i++)
            scanf("%d", &tax[i]);

    for (int i=1; i<=len; i++)
        for (int j=1; j<=len; j++)
            nx[i][j] = j;
}
void floyd()
{
    for (int k=1; k<=len; ++k)
        for (int i=1; i<=len; ++i)
            for (int j=1; j<=len; ++j)
            {
                if ( dis[i][j] > dis[i][k]+dis[k][j]+tax[k] )
                {
                    dis[i][j] = dis[i][k]+dis[k][j]+tax[k]; 
                    nx[i][j] = nx[i][k];
                }
                else if ( dis[i][j] == dis[i][k]+dis[k][j]+tax[k] )
                    if ( nx[i][j] > nx[i][k] && i!=k )
                        nx[i][j] = nx[i][k];
            }
}

void output(int a, int b)
{
    int cost = dis[a][b];
    printf("From %d to %d :\n", a, b);
    printf("Path: %d", a);
    while ( a != b )
    {
        printf("-->%d", nx[a][b]);
        a = nx[a][b];
    }
    printf("\nTotal cost : %d\n", cost);
}


int main ()
{
    int t, set = 0;
    scanf("%d", &t);
    while ( t-- )
    {
        if ( set++ )
            puts("");

        init();

        floyd();

        int time = 0;
        getchar();
        while ( fgets(buf, sizeof(buf), stdin) != NULL )
        {
            if ( *buf == '\n' )
                break;

            sscanf(buf, "%d%d", &a, &b);
            if ( time++ )
                puts("");

            output(a, b);
        }
    }
    return 0;
}
