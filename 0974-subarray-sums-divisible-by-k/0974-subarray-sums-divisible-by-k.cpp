class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1; 

        int prefixsum = 0;
        int count = 0;
        int rem;

        for (int num : nums) {
            prefixsum+=num;
            rem=prefixsum%k;

            if (rem < 0){
                rem += k;  
            }
               if(m.count(rem)){
                count+=m[rem];
                m[rem]++;
               }
              else{
                m[rem]=1;
              }
            
        }
        return count;
    }
};