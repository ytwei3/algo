//
/* 207 - Minimum Effort? */
//
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#define endl "\n"
using namespace std;

struct CStringHash
{
    size_t operator () (const cstring &s) const
    {
        return hash<cstring>()(static_cast<LPCSTR>(s));
    }
};

int t, n;
char str[201][1001];
unordered_map<char*, int> m;

int main ()
{
    while ( scanf("%d", &t) )
    {
        for (int i=0; i<t; i++)
        {
            scanf("%[ a-z]", str[i]);
            m[str[i]] = i;
        }
        scanf("%d", &t);
        while ( t-- )
        {
            scanf("%[ a-z]", str);
        }
    }
    return 0;
}

