//
// My scratching file!!
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;

int main()
{
    char str[5];

    while ( ~scanf("%[^\n]", str) )
    {
        getchar();

        puts("test range-based loop");
        for ( int i=0; str[i] != '\0'; i++ )
            printf("%d", str[i]);
        printf("\n");

    }

    return 0;
}
