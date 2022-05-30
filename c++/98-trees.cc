//
/* 98 - Trees */
//
#include <cstdio>

int p[505];

void res(int t)
{
    if ( t > 1 )
        printf("A forest of %d trees.\n", t);
    else if ( t == 1 )
        printf("There is one tree.\n");
    else
        printf("No trees.\n");
}
int find(int x)
{
    return p[x] < 1 ? x : p[x] = find(p[x]);
}

int main()
{
    int time = 1;
    int n, m, a, b, c, d;
    while ( scanf("%d%d", &n, &m) && ( n || m ) )
    {
        for (int i=1; i<=n; ++i)
            p[i] = -1;

        while ( m-- )
        {
            scanf("%d%d", &a, &b);
            c = find(a), d = find(b);

            if ( c != d )
                if ( p[c] == 0 )
                    p[d] = c;
                else
                    p[c] = d;
            else
                p[c] = 0;
        }

        int t = 0;
        for (int i=1; i<=n; ++i)
            if ( p[i] == -1 )
                t++;

        printf("Case %d: ", time++);
        res(t);
    }
    return 0;
}
