#include <cstdio>
#include <cstring>
#define MAX_SIZE 1000000

// Returns the longest repeating non-overlapping
// substring in str
string longestRepeatedSubstring(string str)
{
    int n = str.length();
    int LCSRe[n+1][n+1];
 
    // Setting all to 0
    memset(LCSRe, 0, sizeof(LCSRe));
 
    string res; // To store result
    int res_length  = 0; // To store length of result
 
    // building table in bottom-up manner
    int i, index = 0;
    for (i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            // (j-i) > LCSRe[i-1][j-1] to remove
            // overlapping
            if (str[i-1] == str[j-1] &&
                LCSRe[i-1][j-1] < (j - i))
            {
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1;
 
                // updating maximum length of the
                // substring and updating the finishing
                // index of the suffix
                if (LCSRe[i][j] > res_length)
                {
                    res_length = LCSRe[i][j];
                    index = max(i, index);
                }
            }
            else
                LCSRe[i][j] = 0;
        }
    }
 
    // If we have non-empty result, then insert all
    // characters from first character to last
    // character of string
    if (res_length > 0)
        for (i = index - res_length + 1; i <= index; i++)
            res.push_back(str[i-1]);
 
    return res;
}

int main()
{
	long size;
	char buf[MAX_SIZE];
	while (fgets(buf, sizeof(buf), stdin)) {
		size = strlen(buf);
		for (int i=0; i<size; i++) 
		printf("this test case: %ld\n", size);
	}
	return 0;
}