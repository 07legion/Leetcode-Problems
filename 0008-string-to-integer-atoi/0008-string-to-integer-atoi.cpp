typedef long long int ll;

class Solution {
public:
    int myAtoi(string s) {
        ll ans = 0;
        while(s.length() && s[0] == ' ') {
            s.erase(s.begin());
        }
        ll i = 0, mul = 1;
        if (s[i] == '-') {
            mul = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        for(;i<s.length();i++) {
            if (s[i] < '0' || s[i] > '9') break;
            if (mul*ans < -2147483648) 
                return -2147483648;
            if (mul*ans > 2147483647)
                return 2147483647;
            ans *= 10;
            ans += s[i] - '0';
        }
        ans *= mul;
        if (ans < -2147483648) ans = -2147483648;
        else if (ans > 2147483647) ans = 2147483647;
        return ans;
    }
};