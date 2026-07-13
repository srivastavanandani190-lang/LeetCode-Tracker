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
 int total(TreeNode*root ,int &count){
      if(root==NULL){
          return 0;
      }
      count++;
      total(root->left,count);
      total(root->right,count);
      return count;
  }
    int countNodes(TreeNode* root) {
        int count=0;
        int Count=total(root,count);
        return Count;
    }
};