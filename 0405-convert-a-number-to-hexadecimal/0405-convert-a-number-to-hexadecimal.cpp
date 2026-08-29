class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        // Cast to unsigned int to handle two's complement for negative numbers naturally
        unsigned int n = num; 
        string hex_chars = "0123456789abcdef";
        string result = "";
        
        while (n > 0) {
            // Get the last 4 bits and map to the corresponding hex character
            result += hex_chars[n & 15]; 
            // Shift right by 4 bits
            n >>= 4; 
        }
        
        // Since we extract digits from least to most significant, reverse the string
        reverse(result.begin(), result.end());
        
        return result;
    }
};