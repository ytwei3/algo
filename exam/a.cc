#include <stdio.h>
#include <stack>

int t, n, number;

int main () 
{
    while ( scanf("%d", &t) != EOF )
    {
        while (t--)
        {
            std::stack<int> s;
            scanf("%d", &n);
            while ( n-- )
            {
                scanf("%d", &number);
                if (number > 0 )
                    s.push(number);
            }

            if ( s.empty() )
            {
                printf("\n");
                continue;
            }
            else
            {
                printf("%d", s.top() );
                s.pop();
                while ( !s.empty() )
                {
                    printf(" %d", s.top() );
                    s.pop();
                }
                printf("\n");
            }
        }
    }
    return 0;
}
