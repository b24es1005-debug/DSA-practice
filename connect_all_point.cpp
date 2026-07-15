class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // Min-heap: {cost, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<bool> vis(n, false);

        pq.push({0, 0});      // Start from node 0

        int cost = 0;
        int nodesVisited = 0;

        while (nodesVisited < n) {

            auto [wt, node] = pq.top();
            pq.pop();

            // Skip if already included in MST
            if (vis[node])
                continue;

            vis[node] = true;
            cost += wt;
            nodesVisited++;

            // Try connecting every unvisited point
            for (int next = 0; next < n; next++) {

                if (!vis[next]) {

                    int dist =
                        abs(points[node][0] - points[next][0]) +
                        abs(points[node][1] - points[next][1]);

                    pq.push({dist, next});
                }
            }
        }

        return cost;
    }
};