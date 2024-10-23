class TrieNode {
    public:
    TrieNode* links[26];
    int c=0;
};

class Trie {
    public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string &s) {
        TrieNode* node=root;
        for(auto &ch:s)
        {
            if(!node->links[ch-'a'])
                node->links[ch-'a']=new TrieNode();
            
            node=node->links[ch-'a'];
            node->c++;
        }
        
    }

    int common(string &s) {
        TrieNode* node=root;
        int res=0;
        for(auto &ch:s)
        {
            if(!node->links[ch-'a'])
                return res;
            node=node->links[ch-'a'];
            res+=node->c;
        }
        return res;
    }
};