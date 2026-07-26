class Solution {
public:
 string add(string nums1, string nums2){
    string ans;
    int i1=nums1.size()-1;
    int i2=nums2.size()-1;
    int carry=0,sum;
    while(i2>=0){
        sum=(nums1[i1]-'0')+(nums2[i2]-'0')+carry;
        carry=sum/10;
        char c='0'+(sum%10);
        ans+=c;
        i1--;
        i2--;
    }
    while(i1>=0){
        sum=(nums1[i1]-'0')+carry;
        carry=sum/10;
        char c='0'+(sum%10);
        ans+=c;
        i1--;
    }
    if(carry){
        ans+='1';
    }
    reverse(ans.begin(),ans.end());
    return ans;
 }
    string addStrings(string num1, string num2) {
       if(num1.size()<num2.size()){
        return add(num2,num1);
       }
       else{
        return add(num1,num2);
       }
       
    }
};