// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution {   
    public:
    void booleanMatrix(vector<vector<int> > &v) {
        int n = v.size(), m = v[0].size();
        bool row = false, col = false;
        for(int i=0;i<n;i++) {
            if (v[i][0] == 1) col = true;
        }
        for(int i=0;i<m;i++) {
            if (v[0][i] == 1) row = true;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (v[i][j] == 1) {
                    v[i][0] = 1;
                    v[0][j] = 1;
                }
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if (v[i][0] == 1 || v[0][j] == 1) {
                    v[i][j] = 1;
                }
            }
        }
        if (row) {
            for(int i=0;i<m;i++) v[0][i] = 1;
        }
        if (col) {
            for(int i=0;i<n;i++) v[i][0] = 1;
        }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


  // } Driver Code Ends