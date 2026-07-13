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
    int count(TreeNode* root, int maxi) {
        if (root == NULL)
            return 0;

        int ans = 0;
        if (root->val >= maxi)
            ans = 1;

        maxi = max(maxi, root->val);

        ans += count(root->left, maxi);
        ans += count(root->right, maxi);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        return count(root, root->val);
    }
};