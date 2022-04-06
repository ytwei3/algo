//
// 95 - Approximate Sorting
//
#include <stdio.h>

int t, n, ans;
int ar[19][19], p[19];

int less(int a, int b)
{
    return a < b;
}

int main()
{
    while ( ~scanf("%d", &t) && t )
    {
        for (int i=0; i<t; ++i)
            for (int j=0; j<t; ++j)
                scanf("%1d", &ar[i][j]);

        printf("%d", p[0]);
        for (int i=1; i<t; i++)
            printf("%d", p[i]);
        printf("\n%d\n", ans);
    }
    return 0;
}
