class Solution {
private:
    // DFS function to check if a component is bipartite
    // Returns true if bipartite, false if not
    bool dfs(int node, int currentColor, vector<vector<int>>& adj, vector<int>& color) {
        // Color the current node
        color[node] = currentColor;
        
        // Traverse all adjacent nodes
        for(int neighbor : adj[node]) {
            // If neighbor is not colored yet
            if(color[neighbor] == -1) {
                // Recursively color neighbor with opposite color (1 -> 0, 0 -> 1)
                // If any recursive call returns false, propagate false
                if(!dfs(neighbor, !currentColor, adj, color)) {
                    return false;
                }
            }
            // If neighbor has the same color as current node
            // Then graph is not bipartite
            else if(color[neighbor] == currentColor) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(int V, vector<vector<int>>& adj) {
        // Initialize all vertices with no color (-1)
        vector<int> color(V, -1);
        
        // Check each component of the graph
        for(int i = 0; i < V; i++) {
            // If vertex is uncolored, start DFS from it
            if(color[i] == -1) {
                // Start coloring with color 0
                // If any component is not bipartite, return false
                if(!dfs(i, 0, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};