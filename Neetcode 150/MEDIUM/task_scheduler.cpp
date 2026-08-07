class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> freq(26, 0);
        for(char c : tasks){
            freq[c]++;
        }
        int maxFreq = 0;
        for(auto f : freq.second){
            maxFreq = max(maxFreq, f);
        }
        int maxCount = 0;
        for(auto f : freq.second){  
            if(f == maxFreq){
                maxCount++;
            }
        }
        /*say maxfreq of an element is mxfreq there will be mxfreq-1 full blocks of size n+1 and 
        the last block will have maxcount elements in it. maxcount is needed when there are multiple elements with the same maxfreq. 
        So the total length will be (maxfreq-1)*(n+1)+maxcount. 
        But if the number of tasks is greater than this then we can just 
        schedule them one after another so we return max of these two values.
        */
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);

    }
};
