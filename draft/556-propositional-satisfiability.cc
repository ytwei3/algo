//
/* 556 - Propostional Satisfiblity */
//
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
//#include <algorithm>
//#include <cmath>
#define endl "\n"
#define ll long long
using namespace std;

int t, n;
char str[101];
vector<char> v;
stack<char> s;
stack<int> si;
unordered_map<char, int> map;

void i2p() // infix to Postfix
{
    v.clear();
    for (int i=0; i != '\0'; i++)
    {
        char c = str[i];
        if ( isalpha(c) )
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
            while ( !s.empty() && s.top() != '(' && map[s.top()] > map[c] )
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
        if ( isalpha(i) )
            si.push(1);
        else
        {
            if ( map[i] == 4 )
            {
                op1 = si.top(), si.pop();
                op =! op1;
                si.push(op);
            }
            else if ( map[i] == 3 )
            {
                op1 = si.top(), si.pop();
                op2 = si.top(), si.pop();
                op = op1 & op2 ;
                si.push(op);
            }
            else if ( map[i] == 2 )
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
    map['('] = 5, map[')'] = 5;
    map['!'] = 4, map['&'] = 3, map['+'] = 2;

    while ( ~scanf("%s", str) )
    {
        i2p();
        evaluate() ? puts("YES")
                    :puts("NO");
    }
    return 0;
}
