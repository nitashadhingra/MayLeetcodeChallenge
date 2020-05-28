// https://leetcode.com/problems/uncrossed-lines/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/

class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int dp [a.size()+1][b.size()+1];
        for(int i=0 ; i<=a.size() ; i++){
            for(int j=0 ; j<=b.size() ; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[a.size()][b.size()];
    }
};

// Used: Dynamic Programming
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)