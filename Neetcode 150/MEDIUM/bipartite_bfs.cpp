class Solution {
private:
    // BFS function to check if a component is bipartite
    bool checkBipartite(int start, vector<vector<int>>& adj, vector<int>& color) {
        // Color starting node with 0
        color[start] = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Check all neighbors of current node
            for(int neighbor : adj[node]) {
                // If neighbor is not colored yet
                if(color[neighbor] == -1) {
                    // Color with opposite color
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                }
                // If neighbor has same color as current node
                // Then graph is not bipartite
                else if(color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        //Add return true
        return true;
    }
    
public:
    bool isBipartite(int V, vector<vector<int>>& adj) {
        // Initialize all vertices with no color (-1)
        vector<int> color(V, -1);
        
        // Check each component of the graph
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                // If any component is not bipartite, return false
                if(!checkBipartite(i, adj, color)) {
                    return false;
                }
            }
        }
        // Add return true
        return true;
    }
};
/*
Aspect	        Time	Space
BFS Bipartite	O(V + E)	O(V)
DFS Bipartite	O(V + E)	O(V)
Union-Find	O(V + E × α(V))	O(V)
*/