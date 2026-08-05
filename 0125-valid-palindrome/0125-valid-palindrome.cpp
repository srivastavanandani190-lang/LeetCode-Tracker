class Solution {
public:
bool check(string &st,int start,int end){
    if(start>=end){
        return 1;
    }
    if(st[start]!=st[end]){
        return 0;
    }
    return check(st,start+1,end-1);
}
    bool isPalindrome(string s) {
         string st="";
        for(char c:s){
         if(isalnum(c)){
            st+=tolower(c);
         }
        }
        int start=0;
        int end=st.size()-1;
  
       return check(st,start,end);
    }
};