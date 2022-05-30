// 829 - Median
//
// #heap
#include <stdio.h>
#include <vector>
#include <queue>

std::priority_queue< long long, std::vector<long long>, std::less<long long> > maxheap;
std::priority_queue< long long, std::vector<long long>, std::greater<long long> > minheap;

void compare(long long a)
{
    if (maxheap.empty() || maxheap.top() > a )
        maxheap.push(a);
    else
        minheap.push(a);

    // switch when the diff is greater than 1
    if (maxheap.size() > minheap.size() + 1 )
    {
        minheap.push( maxheap.top() );
        maxheap.pop();
    }
    else if ( minheap.size() > maxheap.size() + 1 )
    {
        maxheap.push( minheap.top() );
        minheap.pop();
    }

    return ;
}

int main()
{
    long long a;

    int n;
    scanf("%d", &n);

    while ( n-- )
    {
        scanf("%lld", &a);
        compare(a);

        if ( maxheap.size() > minheap.size() )
            printf("%lld\n", maxheap.top() );
        else if ( maxheap.size() < minheap.size() )
            printf("%lld\n", minheap.top() );

    }
    return 0;
}
