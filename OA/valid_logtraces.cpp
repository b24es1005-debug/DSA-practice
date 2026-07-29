#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    bool isval(string s) {
    stack<char> st;
    for(char c : s){
        if(!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    return st.empty();
}
public:
    vector<int> validLogTraces(vector<string> traces){
        int n = traces.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(isval(traces[i])) ans[i] = 1;
            else ans[i] = 0;
        }
        return ans;
    }

};