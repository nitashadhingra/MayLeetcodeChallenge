// https://leetcode.com/problems/edit-distance/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        for(int i = 0 ; i<=word1.length() ; i++){
            for(int j=0 ; j<=word2.length() ; j++){
                if(i==0)
                    dp[i][j] = j;
                if(j==0)
                    dp[i][j] = i;
                else if(i>0 && j>0){
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

// Used: Dynamic Programming
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)