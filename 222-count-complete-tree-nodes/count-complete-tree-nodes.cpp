class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);

        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getHeight(TreeNode* node, bool left) {
        int height = 0;
        while (node) {
            height++;
            node = left ? node->left : node->right;
        }
        return height;
    }
};
