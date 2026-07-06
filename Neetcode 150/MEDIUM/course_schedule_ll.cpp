class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list
        // adj[i] = list of courses that depend on course i
        vector<vector<int>> adj(numCourses);
        for(auto& edge : prerequisites) {
            int course = edge[0];      // Course that needs prerequisite
            int prereq = edge[1];      // Prerequisite course
            adj[prereq].push_back(course);  // prereq → course
        }
        
        // Step 2: Calculate indegree of each course
        // indegree[i] = number of prerequisites for course i
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
        
        // Step 3: Initialize queue with courses having no prerequisites
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 4: Process courses in topological order
        vector<int> topo;  // Store the order of courses
        
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            topo.push_back(course);  // Add to result when popping
            
            // Remove this course and reduce indegree of dependent courses
            for(int nextCourse : adj[course]) {
                indegree[nextCourse]--;
                
                // If dependent course has no more prerequisites, add to queue
                if(indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // Step 5: Check if all courses can be completed
        // If some courses remain unprocessed, there is a cycle
        if(topo.size() == numCourses) {
            return topo;  // All courses can be completed
        }
        return {};  // Cycle detected, impossible to complete all courses
    }
};