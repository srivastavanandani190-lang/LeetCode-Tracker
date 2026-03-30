class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int pro=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==original){
             pro=nums[i]*2;
             original=pro;
            }
            else{
                pro=original;
            }
        }
        return pro;
    }
};