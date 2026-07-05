class Solution {
private:
    // DFS function to detect cycle in an undirected graph
    // Returns true if cycle is found, false otherwise
    bool detectCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        // Mark current node as visited
        vis[node] = 1;
        
        // Traverse all adjacent nodes
        for(int adjacentNode : adj[node]) {
            // If adjacent node is not visited, recursively check for cycle
            if(!vis[adjacentNode]) {
                if(detectCycle(adjacentNode, node, adj, vis)) {
                    return true;
                }
            }
            // If adjacent node is visited and is not the parent, cycle exists
            else if(adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }
    
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }
        
        // Visited array
        vector<int> vis(V, 0);
        
        // Check for cycle in each component
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detectCycle(i, -1, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
Time	O(V + E) - visits each vertex and edge once
Space	O(V) - recursion stack + visited array
*/