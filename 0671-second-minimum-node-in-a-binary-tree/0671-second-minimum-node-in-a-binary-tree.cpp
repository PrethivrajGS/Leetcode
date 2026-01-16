class Solution {
public:
    long long secondMin = LLONG_MAX;
    int minVal;

    void dfs(TreeNode* node) {
        if (!node) return;

        if (node->val > minVal && node->val < secondMin) {
            secondMin = node->val;
        }

        dfs(node->left);
        dfs(node->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        minVal = root->val;
        dfs(root);

        return (secondMin == LLONG_MAX) ? -1 : secondMin;
    }
};
