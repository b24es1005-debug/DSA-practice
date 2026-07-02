class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> minh;//maxheap will be used for kth smallest
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num:nums){
            minh.push(num);
            if(minh.size()>k){//after popping the elements the kth largest will be at the top.
                minh.pop();
            }
        }
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size()>k){
            minh.pop();
        }
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */