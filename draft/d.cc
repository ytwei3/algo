// file used for scratching!
//#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <queue>


int main ()
{
    int a = 1;
    int b = 0;

    b = a & -a;
    a -= ( a & -a );

    printf("%d %d\n", a, b);


    return 0;
}
