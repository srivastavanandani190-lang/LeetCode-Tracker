class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> m;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

         
            if (mp.find(a) != mp.end()) {
                if (mp[a] != b)
                    return false;
            }
         
            else {
      
                if (m.find(b) != m.end())
                    return false;

                mp[a] = b;
                m.insert(b);
            }
        }
        return true;
    }
};

 