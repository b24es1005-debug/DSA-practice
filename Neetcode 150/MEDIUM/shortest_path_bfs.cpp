class Solution{
public:
    vector<int> shortestpath(int N, int M, int src, vector<vector<int>>& edges){
        vector<vector<int>> adj(N);
        for(auto& it : edges){//creatingn the adj list
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dis(N,1e9);//dis vector with infinite intial dis
        queue<int> q;
        dis[src] = 0;//dis to src is 0
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbor : adj[node]){
                if(dis[node] + 1 < dis[neighbor]){//if you find a better way use that and push into the queue
                    dis[neighbor] = dis[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        vector<int> ans(N,-1);
        for(int i =0;i<N;i++){//non reachable nodes are marked -1
            if(dis[i] != 1e9){
                ans[i] = dis[i];
            }
        }
        return ans;
    }
};