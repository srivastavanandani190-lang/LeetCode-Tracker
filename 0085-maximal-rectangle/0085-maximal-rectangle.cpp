class Solution {
public:
int Rectangle(vector<int>& heights) {
        int n=heights.size();
        vector<int>r(n);
        vector<int>l(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                r[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            r[st.top()]=n;
            st.pop();
        }
          for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                l[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            l[st.top()]=-1;
            st.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>heights(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                    heights[j]=0;
                }
                else{
                    heights[j]+=1;
                }
            }
            ans=max(ans,Rectangle(heights));
        }
        return ans;
    }
};