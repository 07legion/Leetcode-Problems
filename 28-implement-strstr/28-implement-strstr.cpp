class Solution {
public:
    int strStr(string str, string pattern) {
        int n = str.length(), m = pattern.length();
        vector<int> lps(m, 0);
        int i = 1, prevLPS = 0;
        while(i < m) {
            if (pattern[i] == pattern[prevLPS]) {
                lps[i] = prevLPS + 1;
                i++; prevLPS++;
            } else {
                if (prevLPS == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prevLPS = lps[prevLPS - 1];
                }
            }
        }
        i = 0; int j = 0;
        while(i < n) {
            if (str[i] == pattern[j]) {
                i++; j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
            if (j == m) {
                return i - m;
            }
        }
        return -1;
    }
};