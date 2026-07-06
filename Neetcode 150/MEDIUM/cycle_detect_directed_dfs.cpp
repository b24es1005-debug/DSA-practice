class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;          // Mark as visited
        pathVis[node] = 1;      // Mark in current path
        
        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                if(dfs(neighbor, adj, vis, pathVis)) {
                    return true;
                }
            } else if(pathVis[neighbor]) {
                return true;    // Cycle detected
            }
        }
        
        pathVis[node] = 0;      // Remove from current path (backtrack)
        return false;
    }
    
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }
        return false;
    }
};