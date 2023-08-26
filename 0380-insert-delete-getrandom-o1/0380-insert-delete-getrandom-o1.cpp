class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> v;
public:
    RandomizedSet() {
        mp.clear();
        v.clear();
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        v[mp[val]] = v.back();
        mp[v.back()] = mp[val];
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */