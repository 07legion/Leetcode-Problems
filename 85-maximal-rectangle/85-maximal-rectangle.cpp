class Solution {
public:
    vector<pair<int, int> > nextSmallestFromLeft(vector<int> v) {
        stack<pair<int, int> > st;
        int n = v.size();
        vector<pair<int, int> > ans;
        for(int i=0;i<n;i++) {
            if (st.empty()) {
                ans.push_back({-1, -1});
            } else {
                while(!st.empty() && st.top().first >= v[i]) st.pop();
                if (st.empty()) {
                    ans.push_back({-1, -1});
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push({v[i], i});
        }
        return ans;
    }
    vector<pair<int, int> > nextSmallestFromRight(vector<int> v) {
        stack<pair<int, int> > st;
        int n = v.size();
        vector<pair<int, int> > ans;
        for(int i=n-1;i>=0;i--) {
            if (st.empty()) {
                ans.push_back({-1, n});
            } else {
                while(!st.empty() && st.top().first >= v[i]) st.pop();
                if (st.empty()) {
                    ans.push_back({-1, n});
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push({v[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int MAH(vector<int> v) {
        vector<pair<int, int> > nsl, nsr;
        nsl = nextSmallestFromLeft(v);
        nsr = nextSmallestFromRight(v);
        int ans = 0;
        for(int i=0;i<v.size();i++) {
            ans = max(ans, abs(nsr[i].second - nsl[i].second - 1) * v[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& v) {
        int mx = 0;
        vector<int> temp;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].size();j++) {
                if (i == 0) {
                    temp.resize(v[i].size(), 0);
                    temp[j] = v[i][j] - '0';
                } else {
                    if (v[i][j] == '0') temp[j] = 0;
                    else temp[j] += v[i][j] - '0';
                }
            }
            mx = max(mx, MAH(temp));
        }
        return mx;
    }
};