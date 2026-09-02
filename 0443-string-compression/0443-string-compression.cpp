class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 1;
        int count = 1;
        string ans = "";
        
        if (n == 1) {
            return 1;
        }
        
        while (i < n) {
            if (chars[i] == chars[i-1]) {
                count++;
            } else {
                // When a new character is found, append the previous one and its count
                ans += chars[i-1];
                if (count > 1) {
                    ans += to_string(count);
                }
                count = 1; 
            }
            i++;  
        }
        
        
        // Don't forget to append the very last character and its count after the loop ends
        ans += chars[n-1];
        if (count > 1) {
            ans += to_string(count);
        }
        
   
        for (int j = 0; j < ans.size(); j++) {
            chars[j] = ans[j];
        }
        
        return ans.size();
    }
};