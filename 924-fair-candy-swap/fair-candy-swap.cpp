class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    int diff = (sumA - sumB) / 2;  // x - y = diff

    unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

    for (int x : aliceSizes) {
        int y = x - diff;
        if (bobSet.count(y)) {
            return {x, y};
        }
    }

    return {};
    }
};