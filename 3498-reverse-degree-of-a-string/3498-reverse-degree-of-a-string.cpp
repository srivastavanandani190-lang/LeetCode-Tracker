class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
           // Calculate the 1-indexed reversed alphabet position (e.g., 'a' = 26, 'b' = 25)
            int reversed_alphabet_pos = 26 - (s[i] - 'a');
            
            // Multiply by the 1-indexed position in the string and add to sum
            sum += reversed_alphabet_pos * (i + 1);
        }
        return sum;
        
    }
};