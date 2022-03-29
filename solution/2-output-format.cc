#include <stdio.h>

int main()
{
    int t;

    if ( scanf("%d", &t) != EOF )
        printf("%d\n", t);

    while ( scanf("%d", &t) != EOF )
        printf("\n%d\n", t);

    return 0;
}
