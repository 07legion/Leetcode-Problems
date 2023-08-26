class Solution {
public:
    int func(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int ind) {
        int n = needs.size();
        if(ind<0) {
            int ans = 0;
            for(int i=0;i<needs.size();i++) {
                ans += needs[i]*price[i];
            }   
            return ans;
        }
        else {
            bool lte = true;
            for(int i=0;i<n;i++) {
                if(needs[i]<special[ind][i]) {
                    lte = false;
                    break;
                }
            }
            if(lte) {
                int op1 = func(price,special,needs,ind-1);
                int op2 = 0;

                for(int i=0;i<n;i++) {
                    needs[i] = needs[i] - special[ind][i];
                }
                op2 = special[ind][n] + func(price,special,needs,ind);
                for(int i=0;i<n;i++) {
                    needs[i] = needs[i] + special[ind][i];
                }
                return min(op1,op2);
            }
            else {
                return func(price,special,needs,ind-1);
            }
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ind=special.size()-1;
        return func(price,special,needs,ind);
    }
};