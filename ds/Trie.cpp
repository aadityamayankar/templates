class Trie {
    array<Trie*,26> child;
    bool end;
    public:
    Trie() {child.fill(nullptr), end = 0;}
    ~Trie() {child.fill(nullptr);}
    void add(string& s) {
        Trie* node = this;
        for(auto& c : s){
            if(!node->child[c - 'a']) node->child[c - 'a'] = new Trie();
            node = node->child[c - 'a'];
        }
        node->end = 1;
    }

    bool exists(string& word, bool f = 0) {
        Trie* node = this;
        for(auto& c : word){
            if(!node->child[c - 'a']) return 0;
            node = node->child[c - 'a'];
        }
        return !f ? node->end : 1;
    }

    bool startswith(string& word) {
        return exists(word,1);
    }
};