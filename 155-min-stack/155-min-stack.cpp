typedef long long int ll;
class MinStack {
private:
    stack<ll> st;
    ll minElement;
public:
    MinStack() {
        while(!st.empty()) st.pop();
        minElement = 0;
    }
    
    void push(int val) {
        if (st.empty()) {
            minElement = val;
            st.push(val);
            return;
        }
        if (val < minElement) {
            st.push(2 * 1ll * val - minElement * 1ll);
            minElement = val;
            return;
        }
        st.push(val);
        return;
    }
    
    void pop() {
        if (st.top() < minElement) {
            minElement = 2 * 1ll * minElement - st.top() * 1ll;
        }
        st.pop();
    }
    
    int top() {
        if (st.top() < minElement) return minElement;
        return st.top();
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */