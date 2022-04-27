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
private:
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int capacity;
    unordered_map<int, node*> mp;
public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node* temp) {
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
    }
    void deleteNode(node* temp) {
        node* p = temp->prev;
        node* n = temp->next;
        p->next = n;
        n->prev = p;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
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
        if (mp.size() == capacity) {
            node* temp = tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
        }
        node* temp = new node(key, value);
        addNode(temp);
        mp[key] = head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */