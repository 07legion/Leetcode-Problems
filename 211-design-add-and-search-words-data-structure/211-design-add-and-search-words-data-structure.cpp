struct node {
    node* children[26];
    bool end;
    node() {
        for(int i=0;i<26;i++) this->children[i] = NULL;
        this->end = false;
    }
};

class trieClass {
private:
    node* root;
public:
    trieClass() {
        root = new node();
    }
    void insert(string str) {
        node* curr = root;
        for(int i=0;i<str.length();i++) {
            if (!curr->children[str[i] - 'a']) {
                curr->children[str[i] - 'a'] = new node();
            }
            curr = curr->children[str[i]-'a'];
        }
        curr->end = true;
    }
    bool func(node* root, int i, string str) {
        if (i == str.length() && root) return root->end;
        if (!root) return false;
        if (str[i] != '.') {
            return func(root->children[str[i]-'a'], i+1, str);
        } else {
            bool a = false;
            for(int j=0;j<26;j++) 
                a = a || func(root->children[j], i+1, str);
            return a;
        }
    }
    bool search(string str) {
        node* curr = root;
        return func(curr, 0, str);
    }
};

class WordDictionary {
private:
    trieClass* obj;
public:
    WordDictionary() {
        obj = new trieClass();
    }
    
    void addWord(string word) {
        obj->insert(word);
    }
    
    bool search(string word) {
        return obj->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */