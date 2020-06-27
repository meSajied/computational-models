#include <bits/stdc++.h>
using namespace std;

class KnuthMoris{
public:
    //int prefix[INT_MAX];

    int string_match(string text, string pattern){
        int text_length = text.length();
        int pattern_length = pattern.length();
        int prefix[INT_MAX];
        int matched_character = 0;

        for(int i = 0; i < pattern_length; i++){
            prefix[i] = compute_prefix(pattern);
        }

        for(int i = 1; i <= text_length; i++){
            while(matched_character > 0 && pattern[matched_character+1] != text[i]){
                matched_character = prefix[matched_character];
            }

            if(pattern[matched_character+1] == text[i]){
            matched_character++;
            }

            if (matched_character == pattern_length){
                matched_character = prefix[matched_character];
            }
        }
        return matched_character;
    }

    int compute_prefix(string pattern){
        int pattern_length = pattern.length();
        int prefix[INT_MAX];
        prefix[0] = 0;
        int LONGEST_PREFIX_LENGTH = 0;

        for(int matched_character = 1; matched_character <= pattern_length;
                                                            matched_character++){
            while(LONGEST_PREFIX_LENGTH > 0 && pattern[LONGEST_PREFIX_LENGTH+1] != 
                                                    pattern[LONGEST_PREFIX_LENGTH]){
                LONGEST_PREFIX_LENGTH = prefix[LONGEST_PREFIX_LENGTH];
            }

            if(pattern[LONGEST_PREFIX_LENGTH+1] == pattern[matched_character]){
                LONGEST_PREFIX_LENGTH++;
            }
            prefix[matched_character] = LONGEST_PREFIX_LENGTH;
            return prefix[matched_character];
        }
    }
};

int main(){
    
    KnuthMoris kmp;
    string txt = "ABABDABACDABABCABAB"; 
    string pat = "ABABCABAB";
    cout << kmp.string_match(txt, pat) << endl;
    return 0;
}