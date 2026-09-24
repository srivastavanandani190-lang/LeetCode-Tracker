class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        
        vector<int> f1(26, 0), f2(26, 0);
        
        // Initialize the sliding window for the first window of size s1
        for(int i = 0; i < s1.size(); i++){
            f1[s1[i] - 'a']++;  
            f2[s2[i] - 'a']++;  
        }
        
        if(f1 == f2){
            return true;
        }
        
        // Slide the window across the rest of s2
        for(int i = s1.size(); i < s2.size(); i++){
            f2[s2[i] - 'a']++;
            f2[s2[i - s1.size()] - 'a']--;
            
            if(f1 == f2){
                return true;
            }
        }
        
        // Return false if no match is found after checking all windows
        return false;
    }
};