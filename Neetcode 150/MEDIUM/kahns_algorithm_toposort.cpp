class Solution {
public:
    // Kahn's Algorithm for Topological Sort (BFS approach)
    // Returns topological order of a DAG
    vector<int> kahnalgorithm(int V, vector<vector<int>>& adj) {
        
        // Step 1: Calculate indegree of all vertices
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;  // Increment indegree of neighbor
            }
        }
        
        // Step 2: Push all nodes with indegree 0 to queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Process nodes in topological order
        vector<int> ans;
        while(!q.empty()) {  
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Reduce indegree of all neighbors
            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                
                // If indegree becomes 0, add to queue
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Check if cycle exists (optional)
        // If ans.size() != V, graph has a cycle
        // In that case, return empty vector or handle as needed
        if(ans.size() != V) {
            return {};  // Cycle detected, return empty
        }
        
        return ans;
    }
};