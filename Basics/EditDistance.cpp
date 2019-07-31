#include <bits/stdc++.h>
using namespace std;

inline int min(int first, int second, int third){

    return min(min(first, second), third);
}

inline int editDistance(string firstString, string secondString, int firstLength, int secondLength){

    if(firstLength == 0)
        return secondLength;

    else if(secondLength == 0)
        return firstLength;

    else if(firstString[firstLength-1] == secondString[secondLength-1])
        return editDistance(firstString, secondString, firstLength-1, secondLength-1);

    else
        return 1 + min(editDistance(firstString, secondString, firstLength-1, secondLength),
                editDistance(firstString, secondString, firstLength, secondLength-1),
                editDistance(firstString, secondString, firstLength-1, secondLength-1));
}

inline int dynamicEditDistance(string firstString, string secondString, int firstLength, int secondLength){

    int value[1000][1000], i, j;
    for (i = 1; i <= firstLength; i++){
        value[i][0]++;
    }
    for (j = 1; j <= secondLength; j++){
        value[0][j]++;
    }
    for (i = 1; i <= firstLength; i++) {
        for (j = 1; j <= secondLength; j++) {
            if(i == 0)
                value[i][j] = j;
            else if (j == 0)
                value[i][j] = i;
            else if(firstString[i-1] == secondString[j-1])
                value[i][j] = value[i-1][j-1];
            else
                value[i][j] = 1 + min(value[i][j-1], value[i-1][j], value[i-1][j-1]);

        }
    }
    return value[i][j];
}

int main(){

    string firstString, secondString;
    int firstLength, secondLength;

    cin >> firstString >> secondString;

    firstLength = firstString.length();
    secondLength = secondString.length();

    cout << editDistance(firstString, secondString, firstLength, secondLength) << endl;
    cout << dynamicEditDistance(firstString, secondString, firstLength, secondLength) << endl;
    return 0;
}
