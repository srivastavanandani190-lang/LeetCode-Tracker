class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32>b(x);
        bitset<32>c(y);
        string s=b.to_string();
        string r=c.to_string();
        int i=0,j=0;
        int count=0;
        while(i<s.size() && j<r.size()){
            if(s[i]!=r[i]){
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};