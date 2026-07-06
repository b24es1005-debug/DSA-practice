class Solution {
private:
    // DFS function for topological sort
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }
    
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // Step 2: Get topological order
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }
        
        // Step 3: Initialize distances
        vector<int> dist(N, 1e9);
        dist[0] = 0;  // Source is node 0
        
        // Step 4: Process nodes in topological order
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            // If current node is reachable
            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Step 5: Convert unreachable nodes to -1 (optional)
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};