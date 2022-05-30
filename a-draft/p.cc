//
// template for piazza question
//
#include <stdio.h>

int main()
{
    int n;       // submission id
    char r[5];      // Verdict
    scanf("%d", &n);
    scanf("%s", r);

    printf("I would like to know why %s.\n", r);
    printf("I cloud pass all test cases, my submission id is : %d", n);
    return 0;
}

