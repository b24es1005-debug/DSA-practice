vector<int> primsAlgorithm(int N, int M, int src, vector<vector<int>>& edges) {
    // Create adjacency list with {neighbor, weight}
    vector<vector<pair<int, int>>> adj(N);
    for(auto& it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> parent(N, -1);        // Stores parent of each node in MST
    vector<int> key(N, 1e9);          // Minimum weight to connect each node
    vector<bool> inMST(N, false);     // Tracks if node is included in MST
    // Min-heap: {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[src] = 0;                     // Start from source
    pq.push({0, src});
    
    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(inMST[node]) continue;     // Skip if already in MST
        inMST[node] = true;           // Include node in MST
        for(auto& neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;
            
            // If neighbor is not in MST and we found a better way to connect it
            if(!inMST[adjNode] && edgeWeight < key[adjNode]) {
                key[adjNode] = edgeWeight;
                parent[adjNode] = node;
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    // Return parent array (MST structure)
    // parent[i] gives the parent of node i in MST
    // parent[src] will be -1
    return parent;
    // Build MST edges
    vector<vector<int>> mstEdges;
    for(int i = 0; i < N; i++) {
        if(parent[i] != -1) {
            mstEdges.push_back({parent[i], i, key[i]});
        }
    }
    return mstEdges;
}