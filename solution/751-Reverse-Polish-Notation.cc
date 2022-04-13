//
/* 751 - Reverse */
//
#include <iostream>
#include <stack>
#include <string>

long long int operation(int a, int b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '*')
        return b * a;
    else if (op == '-')
        return b - a;
    else 
        return 0; // false
}

int main()
{
    long long int o = 0;
    std::string input;
    std::stack<long long int> st;

    while ( std::getline(std::cin, input) )
    {
        int i =0;
        while ( i < input.size() )
        {
            char c = input[i];
            if ( isdigit(c) )
            {
                c = c - 48;
                st.push(c);
            }
            else 
            {
                int a, b;
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push( operation(a, b, c) );
            }
            i+=2;
        }

        o = st.top();
        st.pop();
        printf("%lld\n", o);

        // check for Ending Condition
        if ( std::cin.eof() )
            break;
    }
    return 0;
}
