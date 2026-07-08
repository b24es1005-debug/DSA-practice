#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;  // Added size for union by size
    
public:
    // Constructor: Initialize DSU with n elements (0 to n)
    // T.C: O(n), S.C: O(n)
    DisjointSet(int n) {
        rank.resize(n + 1, 0);        // Rank for union by rank
        size.resize(n + 1, 1);         // Size for union by size
        parent.resize(n + 1);
        
        // Initialize each node as its own parent
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    // Find ultimate parent with path compression
    // T.C: O(α(n)) ≈ O(1) amortized
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        // Path compression: directly attach node to ultimate parent
        return parent[node] = findUPar(parent[node]);
    }
    
    // Union by Rank (more efficient for Kruskal's)
    // T.C: O(α(n)) ≈ O(1) amortized
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Ultimate parent of u
        int ulp_v = findUPar(v);  // Ultimate parent of v
        
        // If already in same component, no union needed
        if (ulp_u == ulp_v) return;
        
        // Attach smaller rank tree under larger rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            // If ranks are equal, attach one under other and increase rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Union by Size (alternative to union by rank)
    // T.C: O(α(n)) ≈ O(1) amortized
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return;
        
        // Attach smaller size tree under larger size tree
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
    // Check if two nodes are in same component
    // T.C: O(α(n)) ≈ O(1) amortized
    bool isConnected(int u, int v) {
        return findUPar(u) == findUPar(v);
    }
    
    // Get size of component containing node
    // T.C: O(α(n)) ≈ O(1) amortized
    int getComponentSize(int node) {
        int root = findUPar(node);
        return size[root];
    }
    
    // Get number of connected components
    // T.C: O(n)
    int getComponentCount() {
        int count = 0;
        for (int i = 1; i < parent.size(); i++) {
            if (parent[i] == i) count++;
        }
        return count;
    }
};

// ================================================================
// COMPLETE KRUSKAL'S ALGORITHM IMPLEMENTATION
// ================================================================

class Kruskal {
public:
    // Structure to represent an edge
    struct Edge {
        int u, v, weight;
        
        // Constructor
        Edge(int _u, int _v, int _w) : u(_u), v(_v), weight(_w) {}
        
        // For sorting edges by weight
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };
    
    // Function to find MST using Kruskal's algorithm
    // T.C: O(E log E + E α(V)) ≈ O(E log E)
    // S.C: O(V + E)
    vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
        // Sort edges by weight (ascending)
        sort(edges.begin(), edges.end());
        
        // Initialize DSU
        DisjointSet ds(V);
        
        vector<Edge> mst;  // Stores edges in MST
        int mstWeight = 0;  // Total weight of MST
        
        // Iterate through all edges in sorted order
        for (Edge& edge : edges) {
            // If including this edge doesn't form a cycle
            if (!ds.isConnected(edge.u, edge.v)) {
                // Add edge to MST
                mst.push_back(edge);
                mstWeight += edge.weight;
                
                // Union the two vertices
                ds.unionByRank(edge.u, edge.v);
                
                // If we have V-1 edges, MST is complete
                if (mst.size() == V - 1) break;
            }
        }
        
        return mst;
    }
    
    // Function to print MST
    void printMST(vector<Edge>& mst) {
        cout << "Minimum Spanning Tree Edges:" << endl;
        int totalWeight = 0;
        for (Edge& e : mst) {
            cout << e.u << " -- " << e.v << " (weight: " << e.weight << ")" << endl;
            totalWeight += e.weight;
        }
        cout << "Total MST Weight: " << totalWeight << endl;
    }
};

// ================================================================
// BONUS: KRUSKAL FOR MINIMUM SPANNING TREE WITH ADJACENCY LIST
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