class Solution {
public:
    string sortVowels(string s) {
        vector<int>low(26,0);
        vector<int>up(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u'){
                low[s[i]-'a']++;
                s[i]='#';
            }
            else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||s[i]=='U'){
                up[s[i]-'A']++;
                s[i]='#';
            }
        }
        string vowel;
        for(int i=0;i<26;i++){
            char c='A'+i;
            while(up[i]){
                vowel+=c;
                 up[i]--;
            }
        }
        for(int i=0;i<26;i++){
            char c='a'+i;
            while(low[i]){
                vowel+=c;
                 low[i]--;
            }
        }
        int f=0,se=0;
        while(se<vowel.size()){
            if(s[f]=='#'){
                s[f]=vowel[se];
                se++;
            }
            f++;
        }
        return s;
    }
};