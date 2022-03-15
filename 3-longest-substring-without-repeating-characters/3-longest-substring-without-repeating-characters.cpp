class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if (str == "") return 0;
        int ans = 0, prev = 0;
        map<char, int> mp;
        int n = str.length();
        for(int i=0;i<n;i++) {
            if (mp.find(str[i]) != mp.end()) {
                prev = max(prev, mp[str[i]] + 1);
            }
            ans = max(ans, i - prev + 1);
            mp[str[i]] = i;
        }
        return max(0, ans);
    }
};