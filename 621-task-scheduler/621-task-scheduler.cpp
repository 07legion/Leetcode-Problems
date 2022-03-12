class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        vector<int> freq(26, 0);
        for(int i=0;i<v.size();i++) {
            freq[v[i] - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int mx = freq.back();
        int gaps = (mx - 1) * n;
        for(int i=24;i>=0;i--) {
            gaps -= min(mx - 1, freq[i]);
        }
        return gaps > 0 ? gaps + v.size() : v.size();
    }
};



// n = 3
// A: 5
// B: 3
// C: 2
    
    
// A _ _ _ A _ _ _ A _ _ _ A _ _ _ A _ _ _ A