class Solution {
public:
    bool isRobotBounded(string str) {
        int x = 0, y = 0;
        char dir = 'N';
        for(int i=0;i<str.length();i++) {
            if (str[i] == 'G') {
                if (dir == 'N') y++;
                if (dir == 'S') y--;
                if (dir == 'W') x--;
                if (dir == 'E') x++;
            } else if (str[i] == 'L') {
                if (dir == 'N') dir = 'W';
                else if (dir == 'S') dir = 'E';
                else if (dir == 'W') dir = 'S';
                else if (dir == 'E') dir = 'N';
            } else {
                if (dir == 'N') dir = 'E';
                else if (dir == 'S') dir = 'W';
                else if (dir == 'W') dir = 'N';
                else if (dir == 'E') dir = 'S';                
            }
        }
        return (x == 0 && y == 0) || dir != 'N';
    }
};