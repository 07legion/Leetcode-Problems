class Solution {
public:
    int reverse(int temp) {
        string str = "";
        bool flag = false;
        long long int x = temp;
        if (x < 0) {
            x *= -1l;
            flag = true;
        }
        str = to_string(x);
        std::reverse(str.begin(), str.end());
        while(str.length() > 1 && str[0] == '0') {
            str.erase(str.begin());
        }
        long long ans = stol(str);
        if (ans < -1 * pow(2, 31) || ans > pow(2, 31)-1) 
            return 0;
        if (flag) {
            ans *= -1;
        }
        return int(ans);
    }
};