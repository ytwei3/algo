// 746 - Fast Food Restaurant
//
//
#include <stdio.h>
#include <vector>
#include <queue>

int main()
{
    int n;
    while ( scanf("%d", &n) != EOF )
    {
        int os = 0;
        bool isQueue = true;
        std::queue<int> qo;     // queue for o
        int a, o, l;

        // init starting point
        scanf("%d%d%d", &a, &o, &l);
        qo.push(o);
        os = a;
        n--;

        while (n--)
        {
            scanf("%d%d%d", &a, &o, &l);

            if ( a >= os + qo.front() && qo.size() == 1 ) // a2
            {
                os = a;
                qo.pop();
            }
            else if ( a >= os + qo.front() )
            {
                os += qo.front();
                qo.pop();
            }

            if ( qo.size() <= l )
            {
                qo.push(o);
                isQueue = true;
            }
            else 
                isQueue = false;
        }

        if ( isQueue )
        {
            while ( qo.size() > 1 )
            {
                os += qo.front();
                qo.pop();
            }
            printf("%d\n", os);
        }
        else 
            printf("-1\n");
    }
    return 0;
}
