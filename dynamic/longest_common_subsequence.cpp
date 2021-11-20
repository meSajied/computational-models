#include <bits/stdc++.h>
#define FromLeft 1
#define FromUp 2
#define Diagonal 3

using namespace std;

class LongestCommonSubsequence {
public:
	inline int recursive(string columns, string rows, int i, int j) {

		if (i == 0 || j == 0)
			return 0;
		if (columns[i - 1] == rows[j - 1])
			return 1 + recursive(columns, rows, i - 1, j - 1);
		else
			return max(recursive(columns, rows, i, j - 1), 
								recursive(columns, rows, i - 1, j));
	}

	inline int dynamic(string X, string Y) {
		int m = X.length();
		int n = Y.length();

		int L[m+1][n+1];
		int i, j;
		
		for (i=0; i<=m; i++)
{
    for (j=0; j<=n; j++)
    {
    if (i == 0 || j == 0)
        L[i][j] = 0;
 
    else if (X[i-1] == Y[j-1])
        L[i][j] = L[i-1][j-1] + 1;
 
    else
        L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
}
     
/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
return L[m][n];
	}
};

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
	LongestCommonSubsequence lcs;

    int m = strlen(X);
    int n = strlen(Y);

	printf("Length of LCS is %d\n", lcs.recursive(X, Y, m, n));
	cout << lcs.dynamic(X, Y) << endl;
    return 0;
}
