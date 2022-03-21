#include <stdio.h>
#include <unordered_map>

int main()
{
    long long n;
    while ( scanf("%lld", &n) != EOF )
    {
        long long c;
        scanf("%lld", &c);

        long long nums[n];
        std::unordered_map<long long, int> m;
        for (int i=0; i<n; ++i)
        {
            scanf("%lld", &nums[i]);

            if ( !m.count( c+nums[i] ) )
                m[c+nums[i]]=1;
            else 
                m[c+nums[i]]++;
        }

        long long count = 0;
        for (int i=0; i<n; ++i)
            if ( m.count(nums[i]) )
                count+=m[nums[i]];
        
        printf("%lld\n", count);
    }

    return 0;
}

