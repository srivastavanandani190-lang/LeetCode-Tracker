class Solution {
public:
    int findDuplicate(vector<int>& arr) {
          sort(arr.begin(),arr.end());
    int ans,j=1;
    for(int i=0;i<arr.size();i++){
      if(arr[i]==arr[j]){
          ans=arr[i];
          break;
      }
      j++;
    }
    return ans;
    }
};