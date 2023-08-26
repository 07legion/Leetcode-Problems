typedef long long int ll;
class Solution {
private:
    ll dp[101][101];
    vector<int> v;
public:
    ll func(int i, int j, bool player) {

        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) 
            return dp[i][j];

        return !player ? dp[i][j] = max(
            v[i] + func(i+1, j, !player),
            v[j] + func(i, j-1, !player)
        ) : min(
            -v[i] + func(i+1, j, !player), 
            -v[j] + func(i, j-1, !player)
        );

    }
    bool predictTheWinner(vector<int>& vect) {
        v = vect;
        memset(dp, -1ll, sizeof dp);
        ll sm = 0; for(auto it:v) sm += it;
        return func(0, v.size()-1, 0) >= 0;
    }
};



