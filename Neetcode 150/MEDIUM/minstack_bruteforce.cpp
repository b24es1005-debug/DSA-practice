class MinStack {
public:
    stack<int> st;
    stack<int> minst;//maintaining two stacks because we need to return the normal top values not the minst ones.
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()){
            minst.push(val);
        }
        else{
            minst.push(min(val,minst.top()));
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
