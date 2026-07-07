class Solution {
public:
    vector<int> shortestpathBelmanFord(int V, vector<vector<int>>& edges, int S) {
        // Step 1: Initialize distances to infinity (1e8) and set source distance to 0
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        // Step 2: Relax all edges V-1 times
        // After V-1 iterations, dist[] will have the shortest path distances 
        // from the source (if no negative cycles exist).
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                // Each edge is given as {u, v, weight}
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                // If u is reachable and a shorter path to v is found, update dist[v]
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Step 3: Check for negative weight cycles
        // Run relaxation one more time (V-th iteration). 
        // If any distance still improves, a negative cycle exists.
        for (auto it : edges) {  
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                // Negative cycle found, return {-1} as per problem requirement
                return {-1};
            }
        }

        // No negative cycle, return the shortest distances
        return dist;
    }
};
/*
TC = O(V * E)
SC = O(V) 

A shortest path between two vertices in a graph with V vertices can have at most V-1 edges.
Why? Because if it had V or more edges, it would have to repeat at least one vertex, 
forming a cycle. For shortest paths (with no negative cycles), this cycle is unnecessary and 
can be removed to get a shorter or equal path.

Here’s how Bellman‑Ford uses this:

Pass 1 guarantees the correct distance for all paths that use 1 edge.

Pass 2 guarantees the correct distance for all paths that use up to 2 edges.

… and so on.
*/