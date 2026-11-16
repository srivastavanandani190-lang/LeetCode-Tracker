#include <string>

class Solution {
public:
    string digitSum(string s, int k) {
        // Repeat the rounds until the length of s is less than or equal to k
        while (s.length() > k) {
            string next_s = "";
            
            // Divide s into consecutive groups of size k
            for (size_t i = 0; i < s.length(); i += k) {
                int current_sum = 0;
                
                // Calculate the digit sum of the current group
                for (size_t j = i; j < i + k && j < s.length(); ++j) {
                    current_sum += s[j] - '0';
                }
                
                // Append the string representation of the sum to the next string
                next_s += to_string(current_sum);
            }
            
            // Update s for the next round
            s = next_s;
        }
        
        return s;
    }
};