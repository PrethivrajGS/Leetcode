#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto &p : freq) {
            int start = p.first;
            int count = p.second;

            if (count > 0) {
                for (int i = 0; i < k; i++) {
                    if (freq[start + i] < count)
                        return false;
                    freq[start + i] -= count;
                }
            }
        }

        return true;
    }
};