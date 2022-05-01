class KthLargest {
private:
    priority_queue<int, vector<int> , greater<int> > mnHeap;
    int k;
public:
    KthLargest(int K, vector<int>& v) {
        while(!mnHeap.empty()) mnHeap.pop();
        k = K;
        for(int i=0;i<v.size();i++) {
            mnHeap.push(v[i]);
            if (mnHeap.size() == k + 1) {
                mnHeap.pop();
            }
        }
    }
    int add(int val) {
        mnHeap.push(val);
        if (mnHeap.size() == k + 1) mnHeap.pop();
        return mnHeap.top();
    }
};

// k = 4
// 3 4 5 7 


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */