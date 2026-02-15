
class TrieNode {
public:
    TrieNode* child[2];
    
    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            
            node = node->child[bit];
        }
    }
    
    int findMaxXOR(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXor = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            
            if (node->child[opposite]) {
                maxXor |= (1 << i);
                node = node->child[opposite];
            } else {
                node = node->child[bit];
            }
        }
        
        return maxXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int maxResult = 0;
        
        for (int num : nums) {
            insert(root, num);
        }
        
        for (int num : nums) {
            maxResult = max(maxResult, findMaxXOR(root, num));
        }
        
        return maxResult;
    }
};
