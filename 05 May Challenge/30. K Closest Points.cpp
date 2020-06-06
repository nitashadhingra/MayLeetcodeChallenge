// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> dis;
        for(auto &p : points){
            dis.push_back( (p[0]*p[0]) + (p[1]*p[1]) );
        }
        sort(dis.begin(),  dis.end());
        vector<vector<int>> ans;
        for(auto &i : points){
            if((i[0]*i[0]) + (i[1]*i[1]) <= dis[K-1])
                ans.push_back({i[0], i[1]});
        }
        return ans;
    }
};

// Time Complexity: O(NlogN)