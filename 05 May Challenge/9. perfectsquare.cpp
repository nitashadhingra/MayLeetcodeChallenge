class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1;
        int e = num;
        long int m;        
        while(s<=e){
            m = s + (e-s)/2 ;
            if(m*m == num)
                return true;
            if(m*m < num)
                s = m+1;
            else
                e = m-1;
        }
        return false;
    }
};

// Used: Binary Search
// Time Complexity: O(logn)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/
