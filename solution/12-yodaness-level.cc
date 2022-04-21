//
// 12 - Yodaness Level
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
//#include <algorithm>
//#include <cmath>
#define endl "\n"
using namespace std;

int t, n, cnt;
string str;
unordered_map<string, int> m;

vector<int> mergeSort(vector<int> v)
{
    int si = v.size() / 2;
    if ( si < 1 )
        return v;
            
    vector<int> small, large;
    for (int i=0; i<si; ++i)
        small.push_back( v[i] );
    for (int i=si; i<v.size(); ++i)
        large.push_back( v[i] );

    vector<int> s, l, e; // small, large, end
    s = mergeSort(small), l = mergeSort(large);

    int i=0, j=0;
    while ( i<s.size() && j<l.size())
    {
        if ( s[i] < l[j] )
        {
            e.push_back( s[i] );
            i++;
        }
        else
        {
            cnt += s.size() - i;
            e.push_back( l[j] );
            j++;
        }
    }

    while ( i<s.size() )
        e.push_back( s[i++] );

    while ( j<l.size() )
        e.push_back( l[j++] );

    return e;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
        while ( t-- )
        {
            cin >> n;
            vector<int> v;
            cnt = 0;
            for ( int i=1; i<=n; ++i)
            {
                cin >> str;
                m[str] = i;
            }

            for ( int i=1; i<=n; ++i)
            {
                cin >> str;
                v.push_back( m[str] );
            }

            v = mergeSort(v);
            cout << cnt << endl;

            m.clear();
        }

    return 0;
}
