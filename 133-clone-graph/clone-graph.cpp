class Solution {
public:
    unordered_map<Node*, Node*> mp;  // map original -> clone

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // If node already cloned, return clone
        if (mp.find(node) != mp.end())
            return mp[node];

        // Create clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone neighbors
        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(nei));
        }

        return clone;
    }
};
