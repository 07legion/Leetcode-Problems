class MedianFinder {
private:
    priority_queue<int> mxHeap;
    priority_queue<int, vector<int>, greater<int> > mnHeap;
public:
    MedianFinder() {
        while(!mnHeap.empty()) mnHeap.pop();
        while(!mxHeap.empty()) mxHeap.pop();        
    }
    void addNum(int n) {
        if (mxHeap.empty() || n <= mxHeap.top()) {
            mxHeap.push(n);
        } else mnHeap.push(n);
        if (mxHeap.size() > mnHeap.size() + 1) mnHeap.push(mxHeap.top()), mxHeap.pop();
        else if (mxHeap.size() + 1 < mnHeap.size()) mxHeap.push(mnHeap.top()), mnHeap.pop();
    }
    double findMedian() {
        if (mnHeap.size() == mxHeap.size()) return (mxHeap.top() + mnHeap.top()) / 2.0;
        else if (mnHeap.size() < mxHeap.size()) return mxHeap.top();
        else return mnHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */ 