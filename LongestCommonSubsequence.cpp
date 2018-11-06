#include <bits/stdc++.h>
#define FromLeft 1
#define FromUp 2
#define Diagonal 3
using namespace std;

inline int commonSequence(char Columns[], char Rows[], int i, int j) {

    if(i == 0 || j == 0)
        return 0;
    if(Columns[i-1] == Rows[j-1])
        return 1 + commonSequence(Columns, Rows, i-1, j-1);
    else
        return max(commonSequence(Columns, Rows, i, j-1), commonSequence(Columns, Rows, i-1, j));
}

inline int dynamicSequence(char Columns[], char Rows[], int ColumnLength, int RowLength) {

    int Values[1000][1000], i, j, Dimention[1000][1000];
    for (i = 1; i <= ColumnLength; i++) {
        Values[i][0] = 0;
    }
    for (j = 1; j <= RowLength; j++) {
        Values[0][j] = 0;
    }
    for (i = 1; i <= ColumnLength; i++) {
        for (j = 1; j <= RowLength; j++) {
            if(i == 0 || j == 0)
                return 0;
            else if(Columns[i] == Rows[j]) {
                Values[i][j] = Values[i-1][j-1]+1;
                Dimention[i][j] = Diagonal;
            }
            else if(Values[i-1][j] > Values[i][j-1]) {
                Values[i][j] = Values[i-1][j];
                Dimention[i][j] = FromUp;
            }
            else{
                Values[i][j] = Values[i][j-1];
                Dimention[i][j] = FromLeft;
            }
        }
    }
    return Values[strlen(Columns)][strlen(Rows)];
}

inline int PrintSequence() {

}

int main() {
    char X[] = "alsdfkjfjkdsal";
    char Y[] = "fdjskalajfkdsla";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", commonSequence(X, Y, m, n));
    cout << dynamicSequence(X, Y, m, n) << endl;
    return 0;
}