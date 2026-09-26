class Solution {
public:
    int maxSubArray(vector<int>& arr) {
       int maximum=INT_MIN;
      int prefix=0;
      for(int i=0;i<arr.size();i++){
          prefix+=arr[i];
          maximum=max(maximum,prefix);
          if(prefix<0){
              prefix=0;
          }
      }
      return maximum;
    }
};