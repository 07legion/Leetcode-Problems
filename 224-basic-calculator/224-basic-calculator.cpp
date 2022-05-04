class Solution {
public:
    int calculate(string str) {
        //good, hard question lot of steps are there
        int sum = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if (isdigit(ch)) {
                //get the whole number, like if ch is '1' then iterate further to get the number like '15'
                int val = 0;
                while (i < str.size() and isdigit(str[i])) {
                    val = val * 10 + (str[i] - '0');
                    i++;
                }
                i--;//coz, i ab ek no digit pe aa gya, or outer for loop se vo ek age or bdh jaega, ek char miss kr dega islie i-- kia
                val = val * sign;
                sign = 1;//sign ko reset kia
                sum += val;
            }
            else if (ch == '(') {
                //sum dalo stack pe, sign dalo stack pe or fir sign and sum ko reset kro
                st.push(sum);
                st.push(sign);
                //reset sign and sum;
                sum = 0;
                sign = 1;
            }
            else if (ch == ')') {
                //stack se sign nikalo or use sum se multiply krdo
                sum *= st.top();
                st.pop();
                //sum me stack ka top add krdo
                sum += st.top();
                st.pop();
            }
            else if (ch == '-') {
                //minus hota h to sign ko reverse krte hai,bachpn me math me pda tha
                sign *= -1; //sign ko toggle kia hai
            }
        }
        return sum;
    }
};