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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        vector<int> result;
        result.push_back(root->val);          // Root
        result.insert(result.end(), left.begin(), left.end());   // Left
        result.insert(result.end(), right.begin(), right.end()); // Right
        
        return result;
    }
};