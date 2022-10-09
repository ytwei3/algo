//
// My scratching file!!
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <array>
#include <cstring>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;

template< class T >
struct is_copy_assignable {
private:
    template< class U, class
        = decltype(declval<U&>() = declval<U const&>()) >
    static true_type
        try_assignment(U&&);
    static false_type
        try_assignment(...);
public:
    using type = decltype(try_assignment(delval<T>()));
};

void fun(int a, char c) {
    printf("%d %c", a, c);
}

int main()
{
    char c = '!';
    int a = 1;
    fun(c, a);
    return 0;
}
