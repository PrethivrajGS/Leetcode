class Solution {
public:
    void getLeaves(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(root->val);
            return;
        }

        getLeaves(root->left, v);
        getLeaves(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        getLeaves(root1, v1);
        getLeaves(root2, v2);

        return v1 == v2;
    }
};