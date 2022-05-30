// 815 - sorting
//
// reverse the whole process
// recursive to minimium the input and process
#include <stdio.h>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> m;
std::vector<int> v, os, ol;
void sorting (int n)
{
    if ( n == 0 )
        return;

    n--;
    sorting(n);

    int start = v.back();
    v.pop_back();

    m[start] = 0;
    for (int i=start-1; i>=0; --i)
        if ( m[i] == 1 )
        {
            os.push_back(i);
            //printf("%d ", i);
            break;
        }

    for (int i=start; i<m.size(); ++i)
        if ( m[i] == 1 )
        {
            ol.push_back(i);
            //printf("%d\n", i);
            break;
        }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i=0; i < n+2; ++i)
        m[i] = 1;

    int s;
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &s);
        v.push_back(s);
    }

    sorting(n);

    for (int i=ol.size()-1; i>=0; --i)
        printf("%d %d\n", os[i], ol[i]);

    return 0;
}
