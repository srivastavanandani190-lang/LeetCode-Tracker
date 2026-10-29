class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int count = 0;

        // for(int i = 0; i < nums.size(); i++){
        //     int sum = 0;  // reset sum for each start point
            
        //     for(int j = i; j < nums.size(); j++){
        //         sum += nums[j];
                
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }

        // return count;
         int sum=0,count=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int ans=sum-k;
            if(m.find(ans)!=m.end()){
                count+=m[ans];
            }
            m[sum]++;
        }
        return count;
    }
};