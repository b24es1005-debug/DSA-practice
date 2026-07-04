class Solution {
public:
    // BFS traversal of a graph starting from node 0
    // Parameters:
    //   n: number of nodes in the graph
    //   adj[]: adjacency list representation of the graph (0-indexed)
    // Returns: vector containing BFS traversal order
    vector<int> bfs(int n, vector<int> adj[]) {
        // ✅ FIXED: Use vector instead of VLA (Variable Length Array)
        // VLA is not standard C++ and won't compile on all compilers
        vector<int> vis(n, 0);  // Initialize all nodes as unvisited (0)
        
        // Mark starting node (0) as visited
        vis[0] = 1;
        
        // Vector to store BFS traversal order
        vector<int> bfs;
        
        // Queue for BFS traversal
        queue<int> q;
        
        // Push starting node into queue
        q.push(0);
        
        // Process until queue becomes empty
        while(!q.empty()) {
            // Get front node from queue
            int node = q.front();
            q.pop();
            
            // Add current node to BFS result
            bfs.push_back(node);
            
            // Traverse all neighbors of current node
            for(auto it : adj[node]) {
                // If neighbor is not visited, mark it visited and push to queue
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;  // Mark as visited when pushing to queue
                }
            }
        }
        
        return bfs;
    }
};