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
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int rootValue = start; rootValue <= end; rootValue++) {
            vector<TreeNode*> leftSubtrees = buildTrees(start, rootValue - 1);
            vector<TreeNode*> rightSubtrees = buildTrees(rootValue + 1, end);

            for (TreeNode* leftTree : leftSubtrees) {
                for (TreeNode* rightTree : rightSubtrees) {
                    TreeNode* root = new TreeNode(rootValue);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};