class Solution {
public:
    int prev = -1;
    int minDiff = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};
