class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int total=t.size();
        int st=0;
        int e=0;
        int count=INT_MAX;
        int index=-1;
        int n=s.size();
        while(e<n){
                  m[s[e]]--;
                  if(m[s[e]]>=0){
                    total--;
                  }  
                  while(!total && st<=e){
                    if(count>e-st+1){
                        count=e-st+1;
                        index=st;
                    }
                    m[s[st]]++;
                    if(m[s[st]]>0){
                        total++;
                    }
                    st++;
                  }
                  e++;
        }
        if(index==-1){
            return "";
        }
        string str="";
        for(int j=index;j<index+count;j++){
            str+=s[j];
        }
        return str;

     }
};