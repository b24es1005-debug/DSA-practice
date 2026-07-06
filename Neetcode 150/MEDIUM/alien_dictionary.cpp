class Solution {
private:
    vector<int> kahnalgorithm(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if(ans.size() != V) {
            return {};  // Cycle detected
        }
        return ans;
    }
    
public:
    string foreignDictionary(vector<string>& words) {
        // Step 1: Find all unique characters
        vector<bool> present(26, false);
        for(string& word : words) {
            for(char c : word) {
                present[c - 'a'] = true;
            }
        }
        
        // Step 2: Build adjacency list for unique characters
        vector<vector<int>> adj(26);
        
        // Step 3: Compare adjacent words to find character order
        for(int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            // Check for invalid case: "abc" before "ab"
            if(w1.length() > w2.length() && w1.substr(0, w2.length()) == w2) {
                return "";  // Invalid order
            }
            
            int len = min(w1.length(), w2.length());
            for(int j = 0; j < len; j++) {
                if(w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    adj[u].push_back(v);
                    break;  // Only first different character matters
                }
            }
        }
        
        // Step 4: Map characters to compact indices
        vector<int> charToIndex(26, -1);  // Maps original index → compact index
        vector<char> indexToChar;          // Maps compact index → original character

        for(int i = 0; i < 26; i++) {
            if(present[i]) {               // If character exists in words
                charToIndex[i] = indexToChar.size();  // Assign next compact index
                indexToChar.push_back('a' + i);       // Store actual character
            }
        }

        int V = indexToChar.size();        // Number of unique characters
        
        // Step 5: Build compact adjacency list
        vector<vector<int>> compactAdj(V);  // New adjacency list of size V

        for(int i = 0; i < 26; i++) {
            if(present[i]) {                // Only process existing characters
                int u = charToIndex[i];     // Get compact index of source
        
                for(int v : adj[i]) {       // For each neighbor in original adj
                    if(present[v]) {        // If neighbor exists (should always be true)
                        compactAdj[u].push_back(charToIndex[v]);  // Add with compact index
                    }
                }
            }
        }
        
        // Step 6: Run Kahn's Algorithm
        vector<int> topo = kahnalgorithm(V, compactAdj);
        
        if(topo.empty()) {
            return "";  // Cycle detected
        }
        
        // Step 7: Convert back to string
        string ans = "";
        for(int idx : topo) {
            ans += indexToChar[idx];
        }
        
        return ans;
    }
};