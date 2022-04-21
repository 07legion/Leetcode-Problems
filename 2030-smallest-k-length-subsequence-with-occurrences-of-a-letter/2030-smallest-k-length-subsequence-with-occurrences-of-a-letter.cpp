class Solution {
public:
    string smallestSubsequence(string str, int k, char letter, int repetition) {
        int n = str.length();
        stack<char> st;
        int used = 0, have = 0;
        for(int i=0;i<n;i++) {
            if (str[i] == letter) {
                have++;
            }
        }
        for(int i=0;i<n;i++) {
            while((!st.empty() && st.top() > str[i] && st.size() - 1 + n - i >= k) && (st.top() != letter || have > repetition)) {
                if (st.top() == letter) repetition++;
                st.pop();
            }
            if (st.size() < k) {
                if (str[i] == letter || k - int(st.size()) > repetition) {
                    st.push(str[i]);
                    if (str[i] == letter) repetition--;
                }
            }
            if (str[i] == letter) have--;
        }
        string ans = "";
        while(!st.empty()) ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 0 1 2 3 4 5 6 7 8


// "leetcode"
// 4
// "e"
// 2
// "leet"
// 3
// "e"
// 1
// "bb"
// 2
// "b"
// 2
