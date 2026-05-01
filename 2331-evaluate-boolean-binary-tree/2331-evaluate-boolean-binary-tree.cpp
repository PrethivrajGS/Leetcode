class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        bool leftValue = evaluateTree(root->left);
        bool rightValue = evaluateTree(root->right);

        if (root->val == 2) {
            return leftValue || rightValue;
        }

        return leftValue && rightValue;
    }
};