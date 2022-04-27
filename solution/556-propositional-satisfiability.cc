//
/* 556 - Propostional Satisfiblity */
//
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int t, n;
char str[101];
vector<char> v;
stack<char> s;
stack<int> si;

void i2p() // infix to Postfix
{
    v.clear();
    for (int i=0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if ( c > 96 && c < 123 )
            v.push_back(c);
        else if ( c == '(' )
            s.push(c);
        else if ( c == ')' )
        {
            while ( s.top() != '(' )
            {
                v.push_back( s.top() );
                s.pop();
            }
            s.pop();
        }
        else
        {
            while ( !s.empty() && 
                    s.top() != '(' && s.top() <= c )
            {
                v.push_back( s.top() );
                s.pop();
            }
            s.push(c);
        }
    }
    while ( !s.empty() )
        v.push_back( s.top() ), s.pop();
}
int evaluate()
{
    int ans, op, op1, op2;
    for (auto i : v)
        if ( i > 96 && i < 123 )
            si.push(1);
        else
        {
            if ( i == '!' )
            {
                op1 = si.top(), si.pop();
                op ^= 1;
                si.push(op);
            }
            else if ( i == '&' && si.size() > 1)
            {
                op1 = si.top(), si.pop();
                op2 = si.top(), si.pop();
                op = op1 & op2 ;
                si.push(op);
            }
            else if ( i == '+' && si.size() > 1)
            {
                op1 = si.top(), si.pop();
                op2 = si.top(), si.pop();
                op = op1 | op2 ;
                si.push(op);
            }
        }
    ans = si.top(), si.pop();
    return ans;
}

int main()
{
    while ( ~scanf("%s", str) )
    {
        i2p();
        evaluate() ? puts("YES")
                    :puts("NO");
    }
    return 0;
}
