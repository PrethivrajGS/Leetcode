#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Transform array: +1 for target, -1 otherwise
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (nums[i] == target) ? 1 : -1;
        }

        int prefix = 0;
        long long count = 0;

        map<int, int> freq;
        freq[0] = 1;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            // Count prefix sums < current
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                if (it->first < prefix)
                    count += it->second;
                else
                    break;
            }

            freq[prefix]++;
        }

        return (int)count;
    }
};