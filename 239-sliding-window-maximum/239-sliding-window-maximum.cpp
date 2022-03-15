class Solution {
public:    
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = v.size();
        for(int i=0;i<k;i++) {
            while(!dq.empty() && v[dq.back()] <= v[i]) 
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(v[dq.front()]);
        for(int i=k;i<n;i++) {
            while(!dq.empty() && i-dq.front() >= k) dq.pop_front();
            while(!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();
            dq.push_back(i);
            ans.push_back(v[dq.front()]);
        }
        return ans;
    }
};