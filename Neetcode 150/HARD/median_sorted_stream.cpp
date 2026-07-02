class MedianFinder {
public:
    priority_queue<int> maxheap;//left half
    priority_queue<int,vector<int>,greater<int>> minheap;//right half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top()){//conventio: push first element into the maxheap
            maxheap.push(num);
        }else{
            minheap.push(num);
        }
        if(minheap.size() > maxheap.size()){//adjust the sixe because both need to equal for median
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if(maxheap.size()>minheap.size() +1){//maxheap size can be minheap +1 bcs we push the first element into maxheap regardless of its value
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()){//even no of elements
            return (minheap.top() + maxheap.top())/2.0;
        }
        else return maxheap.top();//odd no of elements
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */