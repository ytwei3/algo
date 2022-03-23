//
// 98 - Trees
//
#include <stdio.h>
#include <algorithm>

int n, m, a, b, tree;
int ar[505];

void res()
{
    if ( tree > 1 )
        printf("A forest of %d trees.\n", tree);
    else if ( tree == 1 )
        printf("There is one tree.\n");
    else
        printf("No trees.\n");
}
int find(int p)
{
    while ( ar[p] > 0)
        p = ar[p];

    return p;
}

int main()
{
    int time = 1;
    while ( 1 )
    {
        scanf("%d%d", &n, &m);
        if ( n == 0 && m == 0 )
            break;

        for (int i=0; i<=n; ++i)
            ar[i] = -1;

        while ( m-- )
        {
            scanf("%d%d", &a, &b);
            int aa, bb;
            aa = std::min( a, b );
            bb = std::max( a, b );

            if ( find(a) == find(b) )
                ar[ find(a) ] = 0;
            else if ( aa <= 0  )
                ar[bb] = aa;
            else
                ar[bb] = find(aa);
        }

        tree = 0;
        for (int i=1; i<=n; ++i)
            if ( ar[i] == -1 )
                tree++;

        printf("Case %d: ", time++);
        res();
    }
    return 0;
}

