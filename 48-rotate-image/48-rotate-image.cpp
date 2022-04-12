class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        // v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
        int n = v.size();
        
        int count = 0;
        while(count < n) {
            int i = 0, j = n - 1 - count;
            int i1 = count, j1 = n-1;
            while(i <= i1) {
                // cout<<"( "<<i<<" "<<j<<", "<<i1<<" "<<j1<<") ";
                swap(v[i][j], v[i1][j1]);
                i++; i1--; j++; j1--;
            } 
            count++;
            // cout<<"\n";
        }
        // cout<<"--\n";
        count = 1;
        while(count < n) {
            int i = count, j = 0;
            int i1 = n-1, j1 = n - 1 - count;
            while(i <= i1) {
                // cout<<"( "<<i<<" "<<j<<", "<<i1<<" "<<j1<<") ";
                swap(v[i][j], v[i1][j1]);                
                i++; i1--;
                j++; j1--;
            } 
            count++;
            // cout<<"\n";
        }
        count = 0;
        while(count < n) {
            int i = n-1, j = n - count - 1;
            int i1 = 0;
            while(i >= i1) {
                swap(v[i][j], v[i1][j]);
                // cout<<"( "<<i<<" "<<j<<", "<<i1<<" "<<j<<") ";
                i--; i1++;
            } 
            count++;
            // cout<<"\n";
        }
    }
};


// 00 01 02 03
// 10 11 12 13
// 20 21 22 23
// 30 31 32 33