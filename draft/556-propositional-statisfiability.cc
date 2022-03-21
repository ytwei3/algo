#include <iostream>
#include <stack>
#include <string>
#include <map>

int calculus(int a, int b, char op)
{
    if ( op == '!' )
        return 0;
    else
        return 0;
}
bool isOpening(char top)
{
    if ( top == '(')
        return true;
    else
        return false;
}
bool hasHigherPriority(int top, int c)
{
    if (top < c)
        return true;
    else 
        return false;
}
void pf(std::string postfix)
{
    int i = 0;
    std::stack<char> st;
    while ( i < postfix.size() )
    {
        char c = postfix[i];
        if ( isalpha(c) )
            st.push(c);
        else 
        {
            int a, b;
            if ( c == '!' )
            {
                a = st.top();
            }
        }



        ++i;
    }
}

int main()
{
    std::string input;
    std::map<char, int> m;
    m['!'] = 4, m['&'] = 3, m['+'] = 2;

    while ( std::getline(std::cin, input) )
    {
        int i = 0; // iterator for input
        int j = 0; // itr for postfix
        std::string postfix;
        std::stack<char> s;

        while ( i< input.size() )
        {
            char c = input[i];
            // convert the infix to postfix
            // delete the ()
            if ( isalpha(c) )
            {
                postfix[j] = 1;
                j++;
            }
            else if ( c == '(' )
                s.push(c);
            else if ( c == ')' )
                while ( !s.empty() &&
                        !isOpening( s.top() ) )
                {
                    postfix[j] = s.top();
                    s.pop();
                    j++;
                }
            else // it is an operator
            {
                while ( !s.empty() && 
                        !isOpening( s.top() ) && // stop at opening
                        hasHigherPriority( m[s.top()], m[c]) )
                {
                    // a process of pop
                    postfix[j] = s.top();
                    s.pop();
                    j++;
                }
                s.push( m[c] );
            }
        }

        // Now we have a postfix string
        std::cout << postfix << std::endl;

        i++;
        if ( std::cin.eof() )
            break;
    }


    // if it is MPF print YES,
    // if not print NO.

    return 0;
}
