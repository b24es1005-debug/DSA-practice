class Solution {
public:
    vector<int> shortestPathDijkstra(int N, int M, int src, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(N);
        for(auto& edge : edges) {  // Use reference to avoid copying
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];      
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Undirected graph
        }
        
        // Step 2: Initialize distances
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        
        // Step 3: Min-heap priority queue {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        // Step 4: Dijkstra's Algorithm
        while(!pq.empty()) {
            int d = pq.top().first;    // Current distance
            int node = pq.top().second; // Current node
            pq.pop();
            
            // Skip outdated entries (lazy deletion)
            if(d > dist[node]) continue;
            
            // Traverse all neighbors
            for(auto& neighbor : adj[node]) {
                int v = neighbor.first;   // Neighbor node
                int wt = neighbor.second; // Edge weight
                
                // Relaxation step
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Step 5: Convert unreachable nodes to -1
        vector<int> ans(N, -1);  
        for(int i = 0; i < N; i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }
        
        return ans;
    }
};