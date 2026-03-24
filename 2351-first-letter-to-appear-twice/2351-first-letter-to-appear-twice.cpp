class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        
        for(char c : s){
            if(seen.count(c)){
                return c; // first character to appear twice
            }
            seen.insert(c);
        }
        
        return ' '; // (won't reach here as per constraints)
    }
};