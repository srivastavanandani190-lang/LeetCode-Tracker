#include <string>
#include <vector>
#include <utility>

class Solution {
public:
    string sortSentence(string s) {
        // Vector to hold pairs of (position, word)
        vector<pair<int, string>> words;
        
        string currentWord = "";
        for (char c : s) {
            if (c >= '1' && c <= '9') {
                // Convert char digit to integer position
                int pos = c - '0';
                words.push_back({pos, currentWord});
                currentWord = ""; // Reset word buffer
            } else if (c != ' ') {
                currentWord += c;
            }
        }
        
        // Place words into a fixed-size vector based on their 1-based index
        vector<string> sortedWords(words.size());
        for (const auto& p : words) {
            sortedWords[p.first - 1] = p.second;
        }
        
        // Reconstruct the sentence
        string result = "";
        for (int i = 0; i < sortedWords.size(); i++) {
            result += sortedWords[i];
            if (i < sortedWords.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};