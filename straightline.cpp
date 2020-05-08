class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()==2)
            return true;

        bool p=false;
        if(c[1][0]-c[0][0] == 0){
            p=true;
        }
        for(int i = 1; i<c.size(); i++){
            if(p && c[i][0]!=c[i-1][0])
                return false;
            if(!p && c[i][0]==c[i-1][0])
                return false;
        }
        if(p)
            return true;

        float m = (c[1][1]-c[0][1])*1.0 / (c[1][0]-c[0][0]);
        for(int i = 2; i<c.size(); i++){
            float m1 = (c[i][1]-c[i-1][1])*1.0 / (c[i][0]-c[i-1][0]);
            if(m1 != m)
                return false;
        }
        return true;
    }
};

// Time Complexity: O(n)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/