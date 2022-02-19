#include "bits/stdc++.h"
class Solution {
public:
    int minimumDeviation(vector<int>& v) {
        if (v.size() == 1) return v[0];
        priority_queue<int> pq;
        int ans = INT_MAX, mn = INT_MAX;
        for(auto &it:v) {
            if (it % 2) it *= 2;
            mn = min(mn, it);
            pq.push(it);
        }
        ans = min(ans, pq.top() - mn);
        while(pq.top() % 2 == 0) {
            // ans = min(ans, pq.top() - mn);
            int a = pq.top();
            pq.push(a / 2);
            mn = min(mn, a / 2);
            pq.pop();
            ans = min(ans, pq.top() - mn);
        }
        // return min(ans, pq.top() - mn);
        return ans;
    }
};