#include <bits/stdc++.h>
#define FromLeft 1
#define FromUp 2
#define Diagonal 3

using namespace std;

class LongestCommonSubsequence {
public:
	inline int recursive(char columns[], char rows[], int i, int j) {

		if (i == 0 || j == 0)
			return 0;
		if (columns[i - 1] == rows[j - 1])
			return 1 + recursive(columns, rows, i - 1, j - 1);
		else
			return max(recursive(columns, rows, i, j - 1), recursive(columns, rows, i - 1, j));
	}

	inline int dynamic(char columns[], char rows[]) {

		int values[1000][1000], i, j, dimention[1000][1000];

		int columnLength = strlen(columns);
		int rowLength = strlen(rows);

		for (i = 0; i < columnLength; i++) {
			values[i][0] = 0;
		}
		for (j = 0; j < rowLength; j++) {
			values[0][j] = 0;
		}
		for (i = 1; i <= columnLength; i++) {
			for (j = 1; j <= rowLength; j++) {
				if (i == 0 || j == 0)
					return 0;
				else if (columns[i] == rows[j]) {
					values[i][j] = values[i - 1][j - 1] + 1;
					dimention[i][j] = Diagonal;
				} else if (values[i - 1][j] > values[i][j - 1]) {
					values[i][j] = values[i - 1][j];
					dimention[i][j] = FromUp;
				} else {
					values[i][j] = values[i][j - 1];
					dimention[i][j] = FromLeft;
				}
			}
			return values[strlen(columns)][strlen(rows)];
		}
	}

	inline int PrintSequence() {

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
