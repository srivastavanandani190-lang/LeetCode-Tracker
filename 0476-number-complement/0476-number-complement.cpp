class Solution {
public:
    int findComplement(int num) {
        bitset<32>b(num);
        string s=b.to_string();
        // Find the index of the first '1' to skip leading zeros
        int first_one = s.find('1');
        
        // Only flip the bits starting from the first '1'
        for(int i = first_one; i < s.size(); i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        bitset<32>ans(s);
        int res=ans.to_ulong();
        return res;
    }
};