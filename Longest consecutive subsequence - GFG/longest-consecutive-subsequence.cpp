// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int v[], int n) {
        map<int, int> mp;
        int ans = 0;
        for(int i=0;i<n;i++) mp[v[i]]++;
        for(int i=0;i<n;i++) {
            if (mp.find(v[i]-1) == mp.end()) {
                int j = v[i];
                while(mp.find(j) != mp.end()) {
                    j++;
                }
                ans = max(ans, j - v[i]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends