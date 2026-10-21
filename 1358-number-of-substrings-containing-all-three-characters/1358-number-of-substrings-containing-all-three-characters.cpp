class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3]={0};
        int l=0,ans=0,n=s.length();
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            while(count[0]>0 && count[1]>0 && count[2]>0 ){
                ans+=n-i;
                count[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};