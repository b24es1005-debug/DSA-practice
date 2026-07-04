struct TrieNode{
    TrieNode* child[26];//root has 26 subnode along with one flag, just like root has left and right in bt
    bool isEnd;
    TrieNode(){
        isEnd = false;//constructor
        for(int i =0;i<26;i++){
            child[i] = NULL;
        }
    }
};


class Trie {
public:
    TrieNode* root = new TrieNode;//main root declared in public
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* node = root;//every operation is made using the dummy node bcs we dont involve the main root
        for(char c :word){
            int idx = c - 'a';//0 to 26 indexed
            if(node->child[idx] == NULL){
                node->child[idx] = new TrieNode;//create new node
            }
            node = node->child[idx];//else procedd with the next
        }
        node->isEnd = true;//after full insertion mark end as true
    }
    
    bool search(string word) {
        TrieNode* node = root;//dummy node
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                return false;
            }
            node = node->child[idx];
        }
        return node->isEnd;//return true only when end is reached
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                return false;
            }
            node = node->child[idx];
        }
        return true;//return true if the prefix is found no need to reach the end
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */