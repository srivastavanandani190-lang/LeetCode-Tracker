class Solution {
public:
    void reverseString(vector<char>& s) {
        // int start=0;
        // int end=s.size()-1;
        // while(start<end){
        //     swap(s[start],s[end]);
        //     start++;
        //     end--;
        // }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty()){
            s[i]=st.top();
            st.pop();
            i++;
        }
        
    }
};