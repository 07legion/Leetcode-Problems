class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        if (v.size() == 0) return 0;
        if (v.size() == 1) return 1;
        if (n == 0) return v.size();
        vector<int> freq(26, 0);
        for(int i=0;i<v.size();i++) {
            freq[v[i]-'A']++;
        }
        sort(freq.begin(), freq.end());
        int gaps = n * (freq.back() - 1);
        for(int i=freq.size()-2;i>=0;i--) {
            gaps -= min(freq[i], freq.back() - 1);
        }
        if (gaps < 0) return v.size();
        return gaps + v.size();
    }
};


// A A A A A A B B B C C,  n = 2

// A B C A B C A B _ A _ _ A _ _ A

// A A A B B B

// A _ _ A _ _ A