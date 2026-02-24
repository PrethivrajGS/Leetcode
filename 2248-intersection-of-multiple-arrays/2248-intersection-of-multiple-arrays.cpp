#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> freq(1001, 0);

        // Count occurrences
        for (auto &arr : nums) {
            for (int num : arr) {
                freq[num]++;
            }
        }

        vector<int> result;

        for (int i = 1; i <= 1000; i++) {
            if (freq[i] == n) {
                result.push_back(i);
            }
        }

        return result;
    }
};