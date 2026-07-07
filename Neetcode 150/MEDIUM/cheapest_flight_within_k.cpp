class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list: node -> {neighbour, price}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[i] = minimum cost to reach node i
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // BFS queue stores {node, cost_to_reach_node}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;
        // Process level by level; each level represents taking one more flight
        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [u, cost] = q.front();
                q.pop();

                for (auto& [v, w] : adj[u]) {
                    // If we find a cheaper way to reach v using exactly (stops+1) flights
                    if (cost + w < dist[v]) {
                        dist[v] = cost + w;
                        q.push({v, dist[v]});
                    }
                }
            }
            stops++; // all nodes in this level have used 'stops' flights so far
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};