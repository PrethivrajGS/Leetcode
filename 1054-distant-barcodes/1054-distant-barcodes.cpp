#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for (int b : barcodes) {
            freq[b]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }
        
        vector<int> result;
        pair<int, int> prev = {0, 0}; 
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            result.push_back(current.second);
            current.first--;
            
            if (prev.first > 0) {
                pq.push(prev);
            }
            
            prev = current;
        }
        
        return result;
    }
};
