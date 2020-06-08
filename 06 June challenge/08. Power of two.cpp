// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        while(n>1){
            if(n%2!=0)
                return false;
            n = n/2;
        }
        if(n==1)
            return true;
        return false;
    }
};

// Time Complexity: O(logn)