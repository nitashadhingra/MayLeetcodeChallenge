// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        
        sort(nums.begin(), nums.end());
        
        int dp[nums.size()];
        int prev[nums.size()];
        for(int i=0; i<nums.size() ; i++)
            dp[i] = 1;
        memset(prev, -1, sizeof(prev));
        for(int i = 1 ; i<nums.size() ; i++){
            int maxi = i;
            for(int j = 0 ; j<i ; j++)
                if(nums[i]%nums[j] == 0 && dp[j] >= dp[maxi])
                    maxi = j;
            if(maxi < i){
                dp[i] += dp[maxi];
                prev[i] = maxi;
            }
        }
        int maxi = 0 ;
        for(int i = 1 ; i<nums.size() ; i++){
            if(dp[i] > dp[maxi]){
                maxi = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxi]);
        while(prev[maxi]!=-1){
            maxi = prev[maxi];
            ans.push_back(nums[maxi]);
        }
        return ans;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)

