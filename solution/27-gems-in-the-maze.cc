// 27 - Gems in the maze
//
//
#include <stdio.h>
#include <vector>

int t, a, b, c, n;

std::vector<int> maze[305];
int vist[305];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &n);
            
        int max = -1;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j < n; ++j)
                vist[j] = 0;

            int cham = i, cnt = 0;
            while ( cham < n && vist[cham] == 0 )
            {
                vist[cham] = 1;
                cnt++;
                cham = (a*cham*cham + b*cham + c) % n;
            }
            if (cnt > max )
                max = cnt;
        }
        printf("%d\n", max);
    }
    return 0;
}
