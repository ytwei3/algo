#include <stdio.h>
#include <stack>

long long maxArea(long long* pp, int num)
{
    long long maxA = 0, tmpA = 0;
    std::stack<int> st;

    int t, itr = 0;
    while ( itr < num )
    {
        if ( st.empty() || pp[ st.top() ] < pp[itr])
            st.push(itr++);
        else // stop, and then calculate the Area
        {
            t = st.top();
            st.pop();
            if ( st.empty() )
                tmpA = pp[t] * (itr);
            else 
                tmpA = pp[t] * ( itr-1-st.top() );

            if ( maxA < tmpA )
                maxA = tmpA;
        }
    }

    while ( !st.empty() )
    {
        t = st.top();
        st.pop();
        if ( st.empty() )
            tmpA = pp[t] * (itr);
        else 
            tmpA = pp[t] * ( itr-1-st.top() );

        if ( maxA < tmpA )
            maxA = tmpA;
    }
    return maxA;
}

int main()
{
    int test, num;
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d", &num);

        long long pp[num];
        for (int i=0; i<num; ++i)
            scanf("%lld", &pp[i]);
        
        printf("%lld\n", maxArea(pp, num) );
    }
    return 0;
}
