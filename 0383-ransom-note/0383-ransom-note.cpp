class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> fre(26, 0);   
        
        for (int i = 0; i < ransomNote.size(); i++) {
            fre[ransomNote[i] - 'a']++;
        }   
        
        for (int i = 0; i < magazine.size(); i++) {
            fre[magazine[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (fre[i] > 0) {
                return false;
            }
        }
        return true;
    }
};