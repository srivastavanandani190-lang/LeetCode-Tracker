class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // Minimum possible open parentheses
        int maxOpen = 0; // Maximum possible open parentheses
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat '*' as ')'
                maxOpen++; // Treat '*' as '('
                           // Treating '*' as empty string means min/max stay the same in their respective branches
            }
            
            // If the maximum possible open parentheses is negative, 
            // it means we have too many ')' to ever be balanced.
            if (maxOpen < 0) return false;
            
            // Minimum open parentheses can't be negative. 
            // If it drops below 0, we just treat some past '*' as empty strings instead of ')'.
            if (minOpen < 0) minOpen = 0;
        }
        
        // If the minimum possible open parentheses is 0, the string is valid.
        return minOpen == 0;
    }
};