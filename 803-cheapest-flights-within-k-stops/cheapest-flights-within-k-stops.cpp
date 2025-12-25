#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int cost = cur[0];
            int node = cur[1];
            int stops = cur[2];

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto &edge : adj[node]) {
                int next = edge.first;
                int price = edge.second;
                int newCost = cost + price;

                if (newCost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }

        return -1;
    }
};
