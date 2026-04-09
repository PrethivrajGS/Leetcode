class Solution {
private:
    int rows, cols;
    int total;
    unordered_map<int, int> mp;

public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        total = m * n;
    }

    vector<int> flip() {
        int r = rand() % total;

        int x = mp.count(r) ? mp[r] : r;
        int last = total - 1;
        mp[r] = mp.count(last) ? mp[last] : last;

        total--;

        return {x / cols, x % cols};
    }

    void reset() {
        mp.clear();
        total = rows * cols;
    }
};