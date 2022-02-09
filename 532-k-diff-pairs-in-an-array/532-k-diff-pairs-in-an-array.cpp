class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        map<int, int> mp;
        int ans = 0;
        set<int> st;
        for(auto it:v) mp[it]++;
        if (k == 0) {
            int t = 0;
            for(auto it:mp) {
                if (it.second >= 2) t++;
            }
            return t;
        }
        for(int i=0;i<v.size();i++) {
            if (st.find(v[i]) != st.end()) continue;
            if (mp.find(v[i]-k) != mp.end()) ans++;
            if (mp.find(v[i]+k) != mp.end()) ans++;
            st.insert(v[i]);
        }
        return ans / 2;
    }
};