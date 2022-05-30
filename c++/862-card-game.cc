//
// 862 - Card Game
//
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, l, s, t;
int ex[105];
queue<long long> q[105];
vector<long long> card;

void init()
{
    card.clear();
    for (int i=0; i<n; i++)
        while ( !q[i].empty() )
            q[i].pop();

    int c;
    for (int i=0; i<n; ++i) 
        for (int j=0; j<l; ++j)
            scanf("%d", &c), q[i].push(c);

    // mark exit
    for (int i=0; i<n; ++i)
        ex[i] = 0;
}

int main()
{
    while ( ~scanf("%d%d%d%d%d", &n, &m, &l, &s, &t) 
            && ( ~n || ~m || ~l || ~s || ~t ) )
    {
        init();
        int player = n;
        for (int k=1; k<=t; k++) // k - round
        {
            for (int i=0; i<n; ++i) // each player
            {
                if ( q[i].empty() )
                    continue;

                int display = q[i].front();

                if ( card.empty() )
                {
                    card.push_back( display );
                    q[i].pop();
                    if ( q[i].empty() )
                        ex[i] = -k, player--;
                    continue;
                }
                
                if ( q[i].front() == s )
                {
                    q[i].pop();
                    for ( auto itr : card )
                        q[i].push(itr);
                    card.clear();
                    q[i].push( display );
                    continue;
                }

                int pos = card.size();
                for (int j=0; j<card.size(); j++)
                    if ( card[j] == display )
                    {
                        pos = j;
                        q[i].pop();
                        break;
                    }

                int time = card.size() - pos;
                if ( time == 0 )
                {
                    card.push_back( display );
                    q[i].pop();
                    if ( q[i].empty() )
                        ex[i] = -k, player--;
                    continue;
                }
                else 
                {
                    for (int j=pos; j<card.size(); j++)
                        q[i].push( card[j] );
                    while ( time-- )
                        card.pop_back();
                    q[i].push( display );
                }
            }
           // printf("This is %d round ending card queue: \n", k);
           // for (auto i : card)
           //     printf("%lld ", i);
           // printf("\n");
           // if ( k == 5 )
           //     for(int it=0; it<n; it++)
           //     {
           //         while ( !q[it].empty() )
           //             printf("%lld ", q[it].front()), q[it].pop();
           //         printf("\n");
           //     }

            if ( player < 2 )
                break;
        }

        // output
        // first line
        if ( ex[0] == 0 )
            printf("%lu", q[0].size());
        else
            printf("%d", ex[0]);

        for (int i=1; i<n; ++i)
            if ( ex[i] == 0 )
                printf(" %lu", q[i].size());
            else
                printf(" %d", ex[i]);
        printf("\n");

        // second line 
        if ( ex[0] == 0 )
        {
            printf("%lld", q[0].front() ), q[0].pop();
            while ( !q[0].empty() )
                printf(" %lld", q[0].front() ), q[0].pop();
        }
        printf("\n");

        for (int i=1; i<n; ++i)
        {
            if ( ex[i] == 0 )
            {
                printf("%lld", q[i].front() ), q[i].pop();
                while ( !q[i].empty() )
                    printf(" %lld", q[i].front() ), q[i].pop();
            }
            printf("\n");
        }
    }
    return 0;
}
