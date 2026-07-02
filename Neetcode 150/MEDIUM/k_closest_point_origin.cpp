//RULE OF THUMB: K smallest/closest use MAXHEAP with size = K, 
//K largest/longest MINHEAP with size = K
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,pair<int,int>>> maxh;
       for(int i = 0;i<points.size();i++){
        int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        maxh.push({d,{points[i][0],points[i][1]}});
        if(maxh.size() > k){
            maxh.pop();
        } 
       } 
       vector<vector<int>> result;
       while(!maxh.empty()){
        auto top = maxh.top();
        maxh.pop();
        result.push_back({top.second.first,top.second.second});
       }
       return result;
    }
};