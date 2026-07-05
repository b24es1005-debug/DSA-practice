class Solution {
private:
    bool detectCycle(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q;//node,parent
        vis[start] = 1;  // ✅ Mark start as visited
        q.push({start, -1});//first node comes from nothing
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {//if not visited I will mark you visited and then I become your parent.
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                } else if(neighbor != parent) {//if already visited but I am not your parent then you are already taouched by someone so cycle detected.
                    return true;  // Cycle found
                }
            }
        }
        return false;
    }
    
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // ✅ Convert to 0-indexed if needed
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // If input is 1-indexed, convert to 0-indexed
            // (Assuming input is already 0-indexed for this problem)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++) {//running on every node to check for all connected components.
            if(!vis[i]) {
                if(detectCycle(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};