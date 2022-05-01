class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        int n = v.size();
        priority_queue<int, vector<int> , greater<int> > mnHeap;
        for(int i=0;i<n;i++) {
            mnHeap.push(v[i]);
            if (mnHeap.size() == k+1) {
                mnHeap.pop();
            }
        }
        return mnHeap.top();
    }
};