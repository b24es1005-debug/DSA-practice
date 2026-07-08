// ================================================================
// KRUSKAL FOR MINIMUM SPANNING TREE WITH ADJACENCY LIST
// ================================================================

class KruskalAdjacency {
public:
    // Edge structure with adjacency list support
    struct Edge {
        int to, weight;
        Edge(int _to, int _weight) : to(_to), weight(_weight) {}
    };
    
    // Convert adjacency list to edge list for Kruskal's
    vector<tuple<int, int, int>> getEdgesFromAdj(int V, vector<vector<Edge>>& adj) {
        vector<tuple<int, int, int>> edges;  // {weight, u, v}
        
        for (int u = 0; u < V; u++) {
            for (Edge& e : adj[u]) {
                if (u < e.to) {  // Add each edge only once
                    edges.push_back({e.weight, u, e.to});
                }
            }
        }
        
        return edges;
    }
    
    int kruskalMST(int V, vector<vector<Edge>>& adj) {
        // Get all edges
        auto edges = getEdgesFromAdj(V, adj);
        
        // Sort edges by weight
        sort(edges.begin(), edges.end());
        
        // Initialize DSU
        DisjointSet ds(V);
        
        int mstWeight = 0;
        int edgeCount = 0;
        
        // Process edges
        for (auto& [weight, u, v] : edges) {
            if (!ds.isConnected(u, v)) {
                ds.unionByRank(u, v);
                mstWeight += weight;
                edgeCount++;
                
                if (edgeCount == V - 1) break;
            }
        }
        
        return mstWeight;
    }
};

// ================================================================
// DRIVER CODE TO TEST KRUSKAL'S ALGORITHM
// ================================================================

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    // Example 1: Simple graph
    // 0---1---2
    //  \  |  /
    //   \ | /
    //     3
    int V = 4;
    vector<Kruskal::Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    Kruskal kruskal;
    vector<Kruskal::Edge> mst = kruskal.kruskalMST(V, edges);
    kruskal.printMST(mst);
    cout << endl;
    
    // Example 2: Test DSU separately
    cout << "=== DSU Testing ===" << endl;
    DisjointSet ds(5);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    
    cout << "Are 1 and 3 connected? " << (ds.isConnected(1, 3) ? "Yes" : "No") << endl;
    cout << "Are 1 and 4 connected? " << (ds.isConnected(1, 4) ? "Yes" : "No") << endl;
    cout << "Component size of 1: " << ds.getComponentSize(1) << endl;
    cout << "Number of components: " << ds.getComponentCount() << endl;
    
    // Example 3: Testing union by size
    DisjointSet ds2(5);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    cout << "\nUnion by Size:" << endl;
    cout << "Component size of 1: " << ds2.getComponentSize(1) << endl;
    
    return 0;
}

// ================================================================
// TEMPLATE FOR QUICK USE (Minimal Version)
// ================================================================

/*
class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
    
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};
*/

// ================================================================
// SUMMARY:
// ================================================================
// | Feature              | Time Complexity | Space Complexity |
// |----------------------|-----------------|------------------|
// | findUPar()           | O(α(n)) ≈ O(1)  | O(1)             |
// | unionByRank()        | O(α(n)) ≈ O(1)  | O(1)             |
// | unionBySize()        | O(α(n)) ≈ O(1)  | O(1)             |
// | isConnected()        | O(α(n)) ≈ O(1)  | O(1)             |
// | Kruskal's Algorithm  | O(E log E)      | O(V + E)         |
// ================================================================
// α(n) = Inverse Ackermann function (practically constant)
// For Kruskal's: Sort edges first, then use DSU
// Total: O(E log E + E α(V)) ≈ O(E log E)
// ================================================================