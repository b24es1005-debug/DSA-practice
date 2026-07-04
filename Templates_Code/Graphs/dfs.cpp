class Solution {
private:
    // DFS traversal starting from a given node
    // Parameters:
    //   node: current node being visited
    //   adj[]: adjacency list of the graph
    //   vis: visited array to track visited nodes
    //   result: vector to store DFS traversal order
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& result) {
        // Mark current node as visited
        vis[node] = 1;
        
        // Add current node to result
        result.push_back(node);
        
        // Traverse all neighbors of current node
        for(auto it : adj[node]) {
            // If neighbor is not visited, recursively visit it
            if(!vis[it]) {
                dfs(it, adj, vis, result);
            }
        }
    }

public:
    // DFS traversal of the graph starting from node 0
    // Parameters:
    //   n: number of nodes in the graph
    //   adj[]: adjacency list representation (0-indexed)
    // Returns: vector containing DFS traversal order
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Vector to store DFS traversal order
        vector<int> result;
        
        // Visited array to track visited nodes
        vector<int> vis(n, 0);  // Initialize all as unvisited (0)
        
        // Start DFS from node 0
        int start = 0;
        dfs(start, adj, vis, result);
        
        return result;
    }
};
/*
TC: O(n + 2E);
SC: S(N);
*/