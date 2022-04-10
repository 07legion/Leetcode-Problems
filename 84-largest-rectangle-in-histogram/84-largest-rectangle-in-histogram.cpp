class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        vector<pair<int, int> > nsl, nsr;
        stack<pair<int, int> > st;
        int n = v.size();
        for(int i=n-1;i>=0;i--) {
            if (st.empty()) nsr.push_back({-1, v.size()});
            else {
                while(!st.empty() && st.top().first >= v[i]) {
                    st.pop();
                }
                if (st.empty()) nsr.push_back({-1, v.size()});
                else nsr.push_back({st.top().first, st.top().second});
            }
            st.push({v[i], i});
        }
        reverse(nsr.begin(), nsr.end());
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++) {
            if (st.empty()) {
                nsl.push_back({-1, -1}); 
            } else {
                while(!st.empty() && st.top().first >= v[i]) {
                    st.pop();
                } 
                if (st.empty()) nsl.push_back({-1, -1});
                else nsl.push_back({st.top().first, st.top().second});
            }
            st.push({v[i], i});
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans, abs(nsr[i].second - nsl[i].second - 1) * v[i]);
        }
        return ans;
    }
};

