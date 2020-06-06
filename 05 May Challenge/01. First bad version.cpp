// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        while(s<=e){
            int m = s+(e-s)/2;
            if(!isBadVersion(m))
                s=m+1;
            else if(!isBadVersion(m-1))
                return m;
            else
                e=m;
        }
        return n;
    }
};

// Used Binary Search
// Time Complexity: O(logn)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/
