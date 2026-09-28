class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int curdepth=0;
        for(int i=0;i<s.size();i++){
         if(s[i]=='(' ){
            curdepth++;
            maxdepth=max(maxdepth,curdepth);
         }
         else if(s[i] == ')') {
                curdepth--;
            }
        }
        return maxdepth;
    }
};