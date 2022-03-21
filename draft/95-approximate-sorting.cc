// 95 - Approximate Sorting
//
//
#include <stdio.h>

int t, n;
int ar[19][19];

int main()
{
    while ( 1 )
    {
        scanf("%d", &t);
        if ( t != 0 )
        {
            for (int i=0; i<t; ++i)
                for (int j=0; j<t; ++j)
                    scanf("%1d", &ar[i][j]);
        }
        else
            break;
    }
    return 0;
}
