    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
class LRUCache {
public:

    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int, node*>mp;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* temp) {
        temp->prev = head;
        temp->next = head->next;
        head->next = temp;
        temp->next->prev = temp;
    }
    void deleteNode(node* temp) {
        node* p = temp->prev;
        node* n = temp->next;
        p->next = n;
        n->prev = p;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        node* temp = mp[key];        
        int ans = temp->val;
        mp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mp[key] = head->next;
        return ans;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* temp = new node(key, value);
        addNode(temp);
        mp[key] = head->next;
    }
};