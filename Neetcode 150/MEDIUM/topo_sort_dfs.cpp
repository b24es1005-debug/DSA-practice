class Solution {
private:
    // DFS function for topological sort
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;  // Mark current node as visited
        
        // Traverse all neighbors
        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                dfs(neighbor, vis, adj, st);
            }
        }
        
        // Push current node to stack after all neighbors are processed
        st.push(node);
    }
    
public:
    // Function to return topological sort of a DAG
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        stack<int> st;                    // Stack to store topological order
        vector<int> vis(V, 0);            
        vector<int> ans;                  // Result vector
        
        // Call DFS for all unvisited nodes
        for(int i = 0; i < V; i++) {      
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        
        // Pop from stack to get topological order
        while(!st.empty()) {
            int node = st.top();          // Get top node
            st.pop();
            ans.push_back(node);          
        }
        
        return ans;                       
    }
};