class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        
        queue<tuple<vector<int>, int, int>> q;
        q.push({{}, 0, 0});

        while (!q.empty()) {
            auto [current, sum, index] = q.front();
            q.pop();

            if (sum == target) {
                result.push_back(current);
                continue;
            }

            for (int i = index; i < candidates.size(); ++i) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                if (sum + candidates[i] > target) break;

                vector<int> next = current;
                next.push_back(candidates[i]);
                q.push({next, sum + candidates[i], i + 1});
            }
        }

        return result;
    }
};