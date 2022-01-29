class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        vector<pair<int, int> > nsr, nsl;
        stack<pair<int, int> > st; // < value, index > 
        int n = v.size();
        for(int i=n-1;i>=0;i--) {
            if (st.empty()) {
                nsr.push_back({-1, v.size()});
            } else {
                while(!st.empty() && st.top().first >= v[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    nsr.push_back({-1, v.size()});
                } else nsr.push_back({st.top().first, st.top().second});
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
                if (st.empty()) {
                    nsl.push_back({-1, -1});
                } else {
                    nsl.push_back({st.top().first, st.top().second});
                }
            }
            st.push({v[i], i});
        }
        // for(auto it:nsl) cout<<"("<<it.first<<", "<<it.second<<") "; cout<<"\n";
        // for(auto it:nsr) cout<<"("<<it.first<<", "<<it.second<<") "; cout<<"\n";
        int ans = 0;
        for(int i=0;i<n;i++) {
            int temp = 0;
            // if (nsl[i].second != -1) {
                temp += abs(i - nsl[i].second) * (v[i]);
            // cout<<temp<<" ";
            // }
            // if (nsr[i].second != -1) {
                temp += abs(i - nsr[i].second) * (v[i]);
            // }
            // cout<<temp<<"\n";
            ans = max({ans, temp-v[i], v[i]});
        }
        return ans;
    }
};