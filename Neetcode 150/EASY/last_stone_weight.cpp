class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(int n : stones){
            maxh.push(n);
        }
        while(maxh.size()>1){
            int wx = maxh.top();
            maxh.pop();
            int wy = maxh.top();
            maxh.pop();
            if(wx != wy){//if not equal push the new stone
                maxh.push(wx - wy);
            }
            //do not need to push anything if both stones are equal bcs we already popped them

        }
        return maxh.empty() ? 0:maxh.top(); 
        
    }
};
