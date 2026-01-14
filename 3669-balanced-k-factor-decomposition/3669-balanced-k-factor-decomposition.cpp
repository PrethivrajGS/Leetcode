class Solution {
public:
    vector<int> best;
    int bestDiff = INT_MAX;

    void dfs(int start, int k, int n, vector<int>& curr) {
        // If we need only one number, it must be n
        if (k == 1) {
            if (n >= start) {
                curr.push_back(n);

                int mn = *min_element(curr.begin(), curr.end());
                int mx = *max_element(curr.begin(), curr.end());

                if (mx - mn < bestDiff) {
                    bestDiff = mx - mn;
                    best = curr;
                }

                curr.pop_back();
            }
            return;
        }

        // Try factors >= start to maintain order
        for (int d = start; d * d <= n; d++) {
            if (n % d == 0) {
                curr.push_back(d);
                dfs(d, k - 1, n / d, curr);
                curr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> curr;
        dfs(1, k, n, curr);
        return best;
    }
};
