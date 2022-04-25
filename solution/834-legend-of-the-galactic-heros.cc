//
/* 834 - Legend of the Galactic Heros */
//
#include <cstdio>
#include <algorithm>

int length[30001];

struct col
{
    int ptr, len;
} p[30001];

col find(int a)
{
    if ( a != p[a].ptr )
    {
        int l = p[a].len;
        p[a] = find( p[a].ptr );
        p[a].len += l;
    }
    return p[a];
}

int main ()
{
    int n;
    scanf("%d", &n);

    for (int i=1; i<=30000; i++)
        p[i] = { i, 0 }, length[i] = 1;

    int a, b;
    char ch;
    while ( n-- )
    {
        scanf(" %c%d%d", &ch, &a, &b);
        col c = find(a), d = find(b);
        if ( ch == 'M' )
        {
            p[ c.ptr ] = {d.ptr, length[ d.ptr ]};
            length[ d.ptr ] += length[ c.ptr ];
        }
        else 
        {
            if ( c.ptr != d.ptr )
                puts("-1");
            else
            {
                int res = abs( c.len - d.len ) - 1;
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
