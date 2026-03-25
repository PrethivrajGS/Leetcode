#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n), rev(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            rev[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            // Normal edges
            for (auto &[v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }

            // Reverse edges (use switch at u)
            for (auto &[v, w] : rev[u]) {
                if (dist[v] > cost + 2LL * w) {
                    dist[v] = cost + 2LL * w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] == LLONG_MAX ? -1 : (int)dist[n-1];
    }
};