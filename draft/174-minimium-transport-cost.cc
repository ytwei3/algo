//
/* 174 - Minimium Transport Cost */
//
#include <stdio.h>
#include <vector>
using namespace std;

int t, n, a, b, len;
vector<int> v[1001], tax;

void query()
{
    printf("YES a is : %d, b is : %d", a, b);
    return ;
}
void clear()
{
    for (int i=0; i<len; i++)
        while ( !v[i].empty() )
            v[i].pop_back();

    while (!tax.empty())
        tax.pop_back();
}

int main ()
{
    scanf("%d", &t);
    while ( t-- )
    {
        while ( 1 )
        {
            scanf("%d", &n);
            v[0].push_back(n);
            if ( getchar() == '\n' )
                break;
        }
        len = v[0].size();
        for (int i=1; i<len; i++)
            for (int j=0; j<len; j++)
            {
                scanf("%d", &n);
                v[i].push_back(n);
            }

        for (int i=0; i<len; i++)
            {
                scanf("%d", &n);
                tax.push_back(n);
            }

        while ( ~scanf("%d%d", &a, &b) )
        {
            char c2 = getchar();
            if (c2 == '\n')
                query();
            else if ( c2 == 32 )
            {
                clear();
                v[0].push_back(a), v[0].push_back(b);
                break;
            }
        }
    }
    return 0;
}
