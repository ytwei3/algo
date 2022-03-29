//
// 862 - Card Game
//
#include <stdio.h>
#include <deque>

int n, m, l, s, t;
int e[105];
std::deque<int> q[105], b;

void init()
{
    int c;
    scanf("%d", &c);
    b.push_back(c);
    for (int j=1; j<l; ++j)
            scanf("%d", &c), q[n-1].push_back(c);

    for (int i=0; i<n-1; ++i) 
        for (int j=0; j<l; ++j)
            scanf("%d", &c), q[i].push_back(c);

    for (int i=0; i<n; ++i)
        e[i] = 0;
}

int main()
{
    while ( ~scanf("%d%d%d%d%d", &n, &m, &l, &s, &t) 
            && ( ~n || ~m || ~l || ~s || ~t ) )
    {
        init();

        int player = n;
        for (int k=1; k<=t; k++)
        {
            for (int i=0; i<n; ++i)
            {
                if ( q[i].empty() )
                    continue;

                // one player action
                // card empty - highest priority
                if ( b.empty() )
                {
                    b.push_back( q[i].front() );
                    q[i].pop_back();
                    if ( q[i].empty() )
                        e[i] = -k, player--;
                    continue;
                }
                else if ( q[i].front() == s )
                {
                    while ( !b.empty() )
                    {
                        q[i].push_back( b.front() );
                        b.pop_front();
                    }
                    q[i].push_back( q[i].front() );
                    q[i].pop_front();
                    continue;
                }

                bool cond = true;
                for ( auto itr = b.begin(); itr != b.end(); ++itr )
                    if ( *itr == q[i].front() )
                    {
                        auto d = itr;
                        while ( itr != b.end() )
                        {
                            q[i].push_back( *itr );
                            itr++;
                        }

                        q[i].push_back( q[i].front() );
                        q[i].pop_front();

                        b.erase( d, b.end() );
                        cond = false;
                        break;
                    }

                if ( cond )
                {
                    b.push_back( q[i].front() );
                    q[i].pop_front();
                    if ( q[i].empty() )
                        player--;
                }
            }
            if ( player < 2 )
                break;
        }

        // output
        int f = n-1;
        if ( e[f] == 0 )
            printf("%lu", q[f].size());
        else
            printf("%d", e[f]);

        for (int i=0; i<n-1; ++i)
            if ( e[i] != 0 )
                printf(" %d", e[i]);
            else
                printf(" %lu", q[i].size());
        printf("\n");

        if ( !q[f].empty() )
        {
            printf("%d", q[f].front() );
            q[f].pop_front();
            while ( !q[f].empty() )
                printf(" %d", q[f].front() ), q[f].pop_front();
        }
        printf("\n");

        for (int i=0; i<n-1; ++i)
        {
            if ( !q[i].empty() )
            {
                printf("%d", q[i].front() );
                q[i].pop_front();
                while ( !q[i].empty() )
                    printf(" %d", q[i].front() ), q[i].pop_front();
            }
            printf("\n");
        }
    }
    return 0;
}
