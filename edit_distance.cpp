#include <bits/stdc++.h>
using namespace std;

inline int min(int first, int second, int third){

        return min(min(first, second), third);
}

class EditDistance{
public:
    inline int recursive(string first_string, string second_string, int first_length, int second_length){

        if(first_length == 0)
            return second_length;

        else if(second_length == 0)
            return first_length;

        else if(first_string[first_length-1] == second_string[second_length-1])
            return recursive(first_string, second_string, first_length-1, second_length-1);

        else
            return 1 + min(recursive(first_string, second_string, first_length-1, second_length),
                    recursive(first_string, second_string, first_length, second_length-1),
                    recursive(first_string, second_string, first_length-1, second_length-1));
    }

    inline int dynamic(string first_string, string second_string, int first_length, int second_length){
        int value[1000][1000], i, j;
        
        for(i = 1; i <= first_length; i++){
            value[i][0]++;
        }

        for(j = 1; j <= second_length; j++){
            value[0][j]++;
        }

        for(i = 0; i <= first_length; i++){
            for(j = 0; j <= second_length; j++){
                if(i == 0)
                    value[i][j] = j;
                else if(j == 0)
                    value[i][j] = i;
                else if(first_string[i-1] == second_string[j-1])
                    value[i][j] = value[i-1][j-1];
                else
                    value[i][j] = 1 + min(value[i][j-1], value[i-1][j], value[i-1][j-1]);

            }
        }
        return value[first_length][second_length];
    }
};