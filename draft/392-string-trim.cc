//
// 392 String Trim (PHP function)
// 
// printf() = sprintf() + puts()
// gets() was banned
// \0, \r, \t are different!
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int t;
char buf[129], str[129];
vector<char> v, f;

int main()
{
    scanf("%d", &t);
    getchar();

    while ( t-- )
    {
        while ( getchar() != '\n' )
        {
            scanf("%[^\"]", buf);
            getchar(), getchar(), getchar();
            scanf("%[^\"]", str);

            puts(buf), puts(str);
            printf("%zu %zu\n", strlen(buf), strlen(str));
        }
    }

    return 0;
}
