//
/* 207 - Minimum Effort? */
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define endl "\n"
using namespace std;


int t, n;
string str;
unordered_map<string, int> m;


int main ()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
    {
        for (int i=0; i<t; i++)
        {
            cin >> str, 
            m[str] = i;
        }

        while ( cin >> n )
            while ( n-- )
            {
                cin.ignore();
                getline(cin, str);
                solve();
            }

    }

    return 0;
}

