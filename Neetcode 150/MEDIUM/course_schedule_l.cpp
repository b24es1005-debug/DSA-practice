class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            adj[prereq].push_back(course);  // prereq → course
        }
        
        // Calculate indegree
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
        
        // Queue with indegree 0 nodes
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Topological sort
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If all courses can be taken, no cycle
        return topo.size() == numCourses;
    }
};