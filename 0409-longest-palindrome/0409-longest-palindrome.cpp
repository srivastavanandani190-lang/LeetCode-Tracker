class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>low(26,0);
        vector<int>up(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'){
                low[s[i]-'a']++;
            }
            else{
               up[s[i]-'A']++; 
            }
        }
        int count=0;
        bool odd=0;
        for(int i=0;i<26;i++){
            if(low[i]%2==0){
                count+=low[i];
            }
            else{
                count+=low[i]-1;
                odd=1;
            }
            if(up[i]%2==0){
                count+=up[i];
            }
            else{
                count+=up[i]-1;
                odd=1;
            }
        }
        return count+odd;
    }
};