class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

private:
    void inorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        inorderHelper(root->left, result); // Left subtree
        result.push_back(root->val);       // Root node
        inorderHelper(root->right, result);// Right subtree
    }
};
