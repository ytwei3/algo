// 748 - Dynamic Quad Tree
// 
// 
#include <stdio.h>
#include <vector>

int main()
{
    int T, k, n;
    printf("The number of T is : ");
    scanf("%d", &T);

    while (T--)
    {
        printf("The number of k is : ");
        scanf("%d", &k);

        n = 1 << k;

        int m;
        printf("The number of m is : ");
        scanf("%d", &m);

        while (m--)
        {
            int r, c, res;
            scanf("%d %d", &r, &c);

            printf("The number should be output is: ");
            printf("%d\n",res);
        }
    }

    return 0;
}
