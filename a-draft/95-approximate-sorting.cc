//
/* 95 - Approximate Sorting */
//
#include <cstdio>

int n, inv;
int ar[19][19], p[19];

int less(int a, int b)
{
    return a < b;
}

int main()
{
    while ( ~scanf("%d", &n) && n )
    {
        for (int i=0; i<n; i++)
            p[i] = i;

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                scanf("%1d", &ar[i][j]);

        printf("%d", p[0]);
        for (int i=1; i<n; i++)
            printf(" %d", p[i]);
        puts("");
        printf("%d", inv);
    }
    return 0;
}
