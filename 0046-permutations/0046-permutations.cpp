class Solution {
public:

void permutation(vector<int>& nums,int n,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visited){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            temp.push_back(nums[i]);
            permutation(nums,n,ans,temp,visited);
            temp.pop_back();
            visited[i]=false;
        }
    }
}

    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>> ans;
    vector<int>temp;
    vector<bool>visited(3,false);
    int n=nums.size();
    permutation(nums,n,ans,temp,visited);
    return ans;
    }
};