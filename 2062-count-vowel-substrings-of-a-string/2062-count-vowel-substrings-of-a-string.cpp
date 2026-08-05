#include <string>
#include <unordered_set>

class Solution {
public:
    int countVowelSubstrings(std::string word) {
        int count = 0;
        int n = word.length();
        
        // Check every possible starting index for the substring
        for (int i = 0; i < n; ++i) {
            std::unordered_set<char> vowels;
            
            // Extend the substring from index i
            for (int j = i; j < n; ++j) {
                char c = word[j];
                
                // If it's a consonant, we cannot form a vowel substring further from here
                if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                    break;
                }
                
                vowels.insert(c);
                
                // If all 5 vowels are present, increment the count
                if (vowels.size() == 5) {
                    count++;
                }
            }
        }
        
        return count;
    }
};