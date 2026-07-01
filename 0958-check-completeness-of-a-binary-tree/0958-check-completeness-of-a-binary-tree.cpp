class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(TreeNode* root, int index, int total) {
        if (!root)
            return true;

        if (index >= total)
            return false;

        return isCBT(root->left, 2 * index + 1, total) &&
               isCBT(root->right, 2 * index + 2, total);
    }

    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return isCBT(root, 0, total);
    }
};