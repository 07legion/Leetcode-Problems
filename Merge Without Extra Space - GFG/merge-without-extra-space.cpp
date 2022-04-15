// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        int nextGap(int gap) {
            if (gap <= 1)
                return 0;
            return (gap / 2) + (gap % 2);
        }
        void merge(long long v1[], long long v2[], int n, int m)  {
            
            int gap = n + m;
            for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
                int i = 0, j = gap;
                while(j < n + m) {
                    if (i < n && j < n) {
                        if (v1[i] > v1[j]) 
                            swap(v1[i], v1[j]);
                    } else if (i < n && j >= n) {
                        if (v1[i] > v2[j - n]) {
                            swap(v1[i], v2[j - n]);
                        }
                    } else {
                        if (v2[i-n] > v2[j-n]) {
                            swap(v2[i-n], v2[j-n]);
                        }
                    }
                    i++; j++;
                }
                
            }
        }
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends