class Solution {
public:
    int minDeletions(string str) {
        if (str == "") return 0;
        int n = str.length();
        vector<int> v(26, 0);
        for(int i=0;i<n;i++) v[str[i] - 'a']++;
        sort(v.begin(), v.end(), greater<int> ());
        int ans = 0;
        // for(auto it:v) cout<<it<<"\n"; 
        set<int> st;
        for(int i=0;i<26;i++) {
            if (st.find(v[i]) == st.end()) {
                st.insert(v[i]);
                continue;
            }
            int t = v[i];
            while(st.find(t) != st.end() && t > 0) {
                t--; ans++;
            }
            if (t > 0 && st.find(t) == st.end()) {
                st.insert(t);
            }
        }
        return ans;
    }
};

// "skjbhsdvchsvdciasbdihsbdlsffefwedf"
// "ncnchfhfnfnjkpoednfgiebrgoqebflihbasfqeirefbqerf"
// "oaoaosdnfwfgnfjjssrffjehqrqwerffqfkhqwvbflhqevrfluheqvbrflhewdfsdfqsrf"