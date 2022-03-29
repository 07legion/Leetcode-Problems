struct node {
    node* children[26];
    int freq;
    node () {
        for(int i=0;i<26;i++) {
            this->children[i] = NULL;
        }
        this->freq = 0;
    }
};
class trie {
private:
    node* root;
public:
    trie() {
        root = new node();
    }
    void insert(string str) {
        node* curr = root;
        for(int i=0;i<str.length();i++) {
            if (!curr->children[str[i]-'a']) {
                curr->children[str[i]-'a'] = new node();
            }
            curr = curr->children[str[i]-'a'];
        }
        curr->freq++;
    }
    bool search(string str) {
        node* curr = root;
        for(int i=0;i<str.length();i++) {
            if (!curr->children[str[i]-'a']) {
                return false;
            }
            curr = curr->children[str[i]-'a'];
        }
        return curr->freq > 0;
    }
    bool isPrefix(string str) {
        node* curr = root;
        for(int i=0;i<str.length();i++) {
            if (!curr->children[str[i]-'a']) {
                return false;
            }
            curr = curr->children[str[i]-'a'];
        }
        return true;
    }
};

class Trie {
private:
    trie* obj;
public:
    Trie() {
        obj = new trie();
    }
    
    void insert(string word) {
        obj->insert(word);
    }
    
    bool search(string word) {
        return obj->search(word);
    }
    
    bool startsWith(string prefix) {
        return obj->isPrefix(prefix);        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */