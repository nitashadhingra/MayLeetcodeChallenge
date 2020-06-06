// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cost) {
        int ans = 0 ;
        vector<pair<int, int>> diff;
        for(int i=0 ; i<cost.size() ; i++)
            diff.push_back(make_pair(cost[i][0] - cost[i][1], i));
        sort(diff.begin(), diff.end());
        
        for(int i=diff.size()-1 ; i>=diff.size()/2 ; i--)
            ans += cost[diff[i].second][1];
            
        for(int i=diff.size()/2-1 ; i>=0 ; i--)
            ans += cost[diff[i].second][0];
        return ans;
    }
};

// Time Complexity: O(nlogn)