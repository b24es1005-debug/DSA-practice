class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list: {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        // Shortest distance from source to every node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // Min-heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            // Ignore outdated entries
            if (time > dist[node])
                continue;
            // Relax all outgoing edges
            for (auto &[next, wt] : adj[node]) {
                if (time + wt < dist[next]) {
                    dist[next] = time + wt;
                    pq.push({dist[next], next});
                }
            }
        }
        int ans = 0;
        // Find the maximum shortest distance
        for (int i = 1; i <= n; i++) {
            // Some node is unreachable
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};