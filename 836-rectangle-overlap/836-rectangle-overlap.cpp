class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec2[2] > rec1[0] && rec2[3] > rec1[1] && 
            rec1[2] > rec2[0] && rec1[3] > rec2[1];
    }
};


//                     x2 y2
             
// x1 y1 x2 y2