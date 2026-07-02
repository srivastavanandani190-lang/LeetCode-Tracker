class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<pair<int, pair<int,int>>> temp;

        for(int i = 0; i < matrix.size(); i++) {
            temp.push_back({matrix[i][0], {i, 0}});
        }

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > p(temp.begin(), temp.end());

        int ans = 0;

        while(k--) {

            auto element = p.top();
            p.pop();

            ans = element.first;

            int i = element.second.first;
            int j = element.second.second;

            if(j + 1 < matrix[i].size()) {
                p.push({matrix[i][j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
   