struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    TrieNode* root = new TrieNode;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool dfs(TrieNode* node, string& word, int index) {
        // Base case: reached end of word
        if(index == word.length()) {
            return node->isEnd;
        }
        
        char c = word[index];
        
        // Case 1: Wildcard - try all 26 letters
        if(c == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->child[i] && dfs(node->child[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
        // Case 2: Regular letter
        else {
            int idx = c - 'a';
            if(!node->child[idx]) return false;
            return dfs(node->child[idx], word, index + 1);
        }
    }

    bool search(string word) {
        TrieNode* node = root;
        return dfs(node,word,0); 
    }
};
