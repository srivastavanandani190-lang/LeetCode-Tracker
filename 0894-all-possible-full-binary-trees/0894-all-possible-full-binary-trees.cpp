/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<TreeNode *>>ans;
    vector<TreeNode*> mycode(int n)
    {
        TreeNode *T;
        if(n==0)
            return {NULL};
        else if(n==1)
        {
            if(ans[1].size()==0)
            {
                T = new TreeNode(0);
                ans[1].push_back(T);
            }
        }
        else if(ans[n].size()==0)
        {
            for(int i=1;i<n;i+=2)
            {
                vector<TreeNode*>LEFT,RIGHT;
                LEFT=mycode(i);//left=i;
                RIGHT=mycode(n-i-1);//right=n-i-1;
            
            for(auto L : LEFT)
            {
                for(auto R : RIGHT)
                {
                    T=new TreeNode(0);
                    T->left=L;
                    T->right=R;
                    ans[n].push_back(T);
                }
            }
            }
        } 

        return ans[n];        
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        ans.resize(n+1);
        if(n%2==0)
            return {};
        mycode(n);
        return ans[n];
    }
};