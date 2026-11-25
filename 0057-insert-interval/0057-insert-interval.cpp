class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int i=0;
        vector<vector<int>>ans;
        while(i<n){
            int st=intervals[i][0];
            int ed=intervals[i][1];
            if(newInterval[0]>ed){
                ans.push_back({st,ed});
            }
            else if(newInterval[1]<st){
                break;
            }
            else{
                newInterval[0]=min(st,newInterval[0]);
                newInterval[1]=max(ed,newInterval[1]);
            }
            i++;
        }
        ans.push_back({newInterval[0],newInterval[1]});
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return ans;
    }
};