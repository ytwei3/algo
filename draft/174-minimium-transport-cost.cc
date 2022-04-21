//
/* 174 - Minimium Transport Cost */
//
#include <cstdio>
#include <vector>
using namespace std;

int t, n, a, b, len;
int nx[1001][1001];
vector<int> v[1001], tax;

void clear()
{
    for (int i=0; i<len; i++)
        while ( !v[i].empty() )
            v[i].pop_back();

    while (!tax.empty())
        tax.pop_back();
}
void floyd()
{
    for (int k=0; k<len; ++k)
        for (int i=0; i<len; ++i)
            for (int j=0; j<len; ++j)
                {
                     v[i][j] = min( v[i][j], v[i][k] + v[k][j] + tax[k] );
                     nx[i][j] = nx[i][k];
                }
}
void output(int a, int b)
{
    int cost = v[a][b];
    printf("From %d to %d :\n", a, b);
    printf("Path: %d", a);
    while ( a != b )
    {
        printf("-->%d", nx[a][b]);
        a = nx[a][b];
    }
    printf("\nTotal cost : %d", cost);
}


int main ()
{
    scanf("%d", &t);
    while ( t-- )
    {
        while ( 1 )
        {
            scanf("%d", &n);
            v[0].push_back(n);
            if ( getchar() == '\n' )
                break;
        }
        // got len
        len = v[0].size();
        for (int i=1; i<len; i++)
            for (int j=0; j<len; j++)
            {
                scanf("%d", &n);
                v[i].push_back(n);
            }

        for (int i=0; i<len; i++)
            {
                scanf("%d", &n);
                tax.push_back(n);
            }

        for (int i=0; i<len; i++)
            for (int j=0; j<len; j++)
                nx[i][j] = j;

        // floyd
        floyd();
        puts("");
        for (int i=0; i<len; i++)
        {
            for (int j=0; j<len; j++)
                printf("%d ", v[i][j]);
            puts("");
        }
        puts("");

        for (int i=0; i<len; i++)
        {
            for (int j=0; j<len; j++)
                printf("%d ", nx[i][j]);
            puts("");
        }

        while ( ~scanf("%d%d", &a, &b) )
        {
            char c2 = getchar();
            if (c2 == '\n')
                //output(a, b);
                printf("cost %d\n", v[a][b]);
            else if ( c2 == 32 )
            {
                clear();
                v[0].push_back(a), v[0].push_back(b);
                break;
            }
        }
    }
    return 0;
}
