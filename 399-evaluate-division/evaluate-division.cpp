#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dst, unordered_set<string>& visited, double product) {
        if (src == dst) return product;
        visited.insert(src);

        for (auto &nbr : graph[src]) {
            string next = nbr.first;
            double value = nbr.second;

            if (!visited.count(next)) {
                double result = dfs(next, dst, visited, product * value);
                if (result != -1.0) return result;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string C = q[0];
            string D = q[1];

            if (!graph.count(C) || !graph.count(D)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = dfs(C, D, visited, 1.0);
            ans.push_back(result);
        }

        return ans;
    }
};
