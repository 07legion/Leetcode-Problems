class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.length(), m = b.length();
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0;i<max(n, m);i++) {
            int t = 0;
            if (i < n) t += a[i] - '0';
            if (i < m) t += b[i] - '0';
            t += carry;
            if (t == 3) {
                ans += '1';
                carry = 1;
            }
            else if (t == 2) {
                ans += '0';
                carry = 1;
            } else {
                ans += char(t + '0');
                carry = 0;
            }
        }
        if (carry > 0) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};