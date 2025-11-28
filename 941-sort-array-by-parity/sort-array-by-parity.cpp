class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evens, odds;

    for (int x : nums) {
        if (x % 2 == 0) evens.push_back(x);
        else odds.push_back(x);
    }

    evens.insert(evens.end(), odds.begin(), odds.end());
    return evens;
    }
};