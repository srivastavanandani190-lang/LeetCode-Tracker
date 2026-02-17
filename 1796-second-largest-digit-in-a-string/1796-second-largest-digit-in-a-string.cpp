class Solution {
public:
    int secondHighest(string s) {
        vector<int> v;
        int res = -1;
        int smax = -1;

       
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                v.push_back(s[i] - '0');   
            }
        }

      
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > res) {
                smax = res;
                res = v[i];
            }
            else if (v[i] < res && v[i] > smax) {
                smax = v[i];
            }
        }

        return smax;
    }
};
