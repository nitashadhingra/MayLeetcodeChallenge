// https://leetcode.com/problems/counting-bits/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/

class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> dp;
        dp.push_back(0);
        for(int i=1;i<=num;i++){
            //for odd number, 1s in even +1
            if(i & 1)
                dp.push_back(dp[i-1]+1);
            //for even number, same 1s as half of it
            else
                dp.push_back(dp[i/2]);
        }
        return dp;
    }
};

// Used: Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)