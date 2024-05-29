#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::unordered_set<int> seen;
    std::unordered_set<int> repeated;
    std::vector<std::string> result;
    int n = s.length();
    
    if (n <= 10) return result;
    
    // Mapping nucleotides to 2-bit values
    std::unordered_map<char, int> charToBits = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int bitmask = 0;
    
    // Initialize the bitmask for the first 10-letter sequence
    for (int i = 0; i < 10; ++i) {
        bitmask = (bitmask << 2) | charToBits[s[i]];
    }
    
    seen.insert(bitmask);
    
    // Process the remaining sequences
    for (int i = 10; i < n; ++i) {
        // Slide the window: remove the leftmost 2 bits and add the new rightmost 2 bits
        bitmask = ((bitmask << 2) & ((1 << 20) - 1)) | charToBits[s[i]];
        
        if (seen.find(bitmask) != seen.end()) {
            // If the bitmask is found in the seen set and not yet added to the result
            if (repeated.find(bitmask) == repeated.end()) {
                result.push_back(s.substr(i - 9, 10));
                repeated.insert(bitmask);
            }
        } else {
            seen.insert(bitmask);
        }
    }
    
    return result;
}

int main() {
    std::string s = "ACGAATTCCGACGAATTCCG";
    std::vector<std::string> result = findRepeatedDnaSequences(s);
    
    for (const std::string& seq : result) {
        std::cout << seq << std::endl;
    }
    
    return 0;
}
