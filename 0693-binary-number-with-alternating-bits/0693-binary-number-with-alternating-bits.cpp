 class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        string s = b.to_string();
        
        // Find the index of the first '1' to skip the leading zeros
        int start = s.find('1');
        
        // Check adjacent bits starting from the first '1'
        for (int i = start; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                return false; // Found two identical bits next to each other
            }
        }
        
        return true;
    }
};