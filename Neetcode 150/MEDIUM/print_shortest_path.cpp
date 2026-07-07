class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Build adjacency list for vertices 1..n
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Parent array to reconstruct the path
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;   // initially each node is its own parent

        // Distance array
        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;                  // source is vertex 1

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1});

        // Dijkstra
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;          // record the predecessor
                    pq.push({dist[v], v});
                }
            }
        }

        // If no path to vertex n
        if (dist[n] == 1e9) return {-1};

        // Reconstruct path from n back to 1
        vector<int> path;
        int curr = n;
        while (curr != 1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);                // add source
        reverse(path.begin(), path.end()); // now path is 1 → ... → n

        // Answer format: [total_weight] + path_nodes
        vector<int> ans;
        ans.push_back(dist[n]);
        ans.insert(ans.end(), path.begin(), path.end());
        return ans;
    }
};