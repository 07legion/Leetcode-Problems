class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> st;
        int len = 0, i = 1, ans = 0; 
        while(len < n) {
            if (st.find(i) == st.end()) {
                st.insert(k-i);
                ans += i;
                len++;
            }
            i++;
        }
        return ans;
    }
};


// n = 5, k = 4
//     1 2 3 4 5
    
    
// k = 11, n = 15


//         1 2 3 4 5 6 7

    
    
//     if (k > n) sum(1 .. k / 2);
//     else {
//         1 2 3 4 5 
//             10 11 12 13 14 15
            

//         1 2 3 4 5 
//             11 12 13 14 15

    // }

    
    
// k = 10, n = 8
    
    
// 1 2 3 4 5 