//
// 392 String Trim (PHP function)
// 
// printf() = sprintf() + puts()
// gets() was banned
// \0, \r, \t are different!
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
//#include <cmath>
//#include <algorithm>
//#include <unoredered_map>
using namespace std;

int t;
string str, res;
vector<char> v, f;

void trim()
{
    auto b = v.begin(), e = v.end()-1;
    if ( f.empty() )
    {
        while ( *b == ' ' && b != e )
            b++;
        
        cout << "\"" << *e  << "\"" << endl;

        while ( *e == ' ' && b != e )
            e--;

        cout << "\"";
        while ( b != e )
        {
            cout << *b;
            b++;
        }
        cout << *b << "\"";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    scanf("%d", &t);

    while ( t-- )
    {
        getline(cin, str);
        int cnt = 0;
        for (auto i : str)
        {
            if ( i == '"' && cnt < 3 )
            {
                cnt++;
                continue;
            }
            else if ( i == '"' && cnt == 3 )
            {
                trim();
                cnt = 0;
                continue;
            }

            if ( cnt < 2 )
                v.push_back(i);
            else
                f.push_back(i);
        }
        cout << res << endl;
    }

    return 0;
}
