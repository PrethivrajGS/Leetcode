#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<vector<int>, int> memo;

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (memo.count(needs)) return memo[needs];

        int n = price.size();
        int minCost = 0;
        for (int i = 0; i < n; i++) {
            minCost += needs[i] * price[i];
        }

        for (auto& sp : special) {
            vector<int> newNeeds(n);
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (sp[i] > needs[i]) {
                    valid = false;
                    break;
                }
                newNeeds[i] = needs[i] - sp[i];
            }

            if (valid) {
                minCost = min(minCost,
                              sp[n] + dfs(price, special, newNeeds));
            }
        }

        return memo[needs] = minCost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};