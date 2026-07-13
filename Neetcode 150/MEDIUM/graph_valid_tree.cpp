class Solution {
private:
    // BFS to detect a cycle in an undirected graph
    bool isCycle(int src, vector<int>& vis, vector<vector<int>>& adj) {

        queue<pair<int, int>> q;   // {node, parent}
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty()) {

            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {

                // Visit unvisited neighbor
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                }

                // Visited neighbor other than parent => cycle found
                else if (neighbor != parent) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree must have exactly (n-1) edges
        if (edges.size() != n - 1)
            return false;

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);

        // If a cycle exists, it is not a tree
        if (isCycle(0, vis, adj))
            return false;

        // Ensure the graph is connected
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }
//return true if ntg before returns 
        return true;
    }
};