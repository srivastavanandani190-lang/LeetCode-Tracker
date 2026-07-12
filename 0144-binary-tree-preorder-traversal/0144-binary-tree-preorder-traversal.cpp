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
void Preorder(TreeNode *root,vector<int>&result){
    if(root==NULL){
        return;
    }
    result.push_back(root->val);
    Preorder(root->left,result);
    Preorder(root->right,result);
}
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>result;
       Preorder(root,result);
        return result;
    }
};