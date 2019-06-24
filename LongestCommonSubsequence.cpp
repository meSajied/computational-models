#include <bits/stdc++.h>
#define FromLeft 1
#define FromUp 2
#define Diagonal 3

using namespace std;

inline int commonSequence(char columns[], char Rows[], int i, int j) {

    if(i == 0 || j == 0)
        return 0;
    if(columns[i-1] == Rows[j-1])
        return 1 + commonSequence(columns, Rows, i-1, j-1);
    else
        return max(commonSequence(columns, Rows, i, j-1), commonSequence(columns, Rows, i-1, j));
}

inline int dynamicSequence(char columns[], char Rows[], int columnLength, int rowLength) {

    int values[1000][1000], i, j, dimention[1000][1000];

    for (i = 1; i <= columnLength; i++) {
        values[i][0] = 0;
    }
    for (j = 1; j <= rowLength; j++) {
        values[0][j] = 0;
    }
    for (i = 1; i <= columnLength; i++) {
        for (j = 1; j <= rowLength; j++) {
            if(i == 0 || j == 0)
                return 0;
            else if(columns[i] == Rows[j]) {
                values[i][j] = values[i-1][j-1]+1;
                dimention[i][j] = Diagonal;
            }
            else if(values[i-1][j] > values[i][j-1]) {
                values[i][j] = values[i-1][j];
                dimention[i][j] = FromUp;
            }
            else{
                values[i][j] = values[i][j-1];
                dimention[i][j] = FromLeft;
            }
        }
    }
    return values[strlen(columns)][strlen(Rows)];
}

inline int PrintSequence() {

}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", commonSequence(X, Y, m, n));
    cout << dynamicSequence(X, Y, m, n) << endl;
    return 0;
}