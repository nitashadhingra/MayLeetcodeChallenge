// https://leetcode.com/problems/interval-list-intersections/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        if(a.size()==0 || b.size()==0)
            return ans;
        int i = 0;
        int j = 0;
        while(i<a.size() && j<b.size()){
            while(i<a.size() && b[j][0] > a[i][1] )
                i++;
            while(i<a.size() && j<b.size() && a[i][0] > b[j][1])
                j++;
            
            if(i<a.size() && 
               j<b.size() &&
               b[j][0] <= a[i][1] && 
               a[i][0] <= b[j][1]){
                
                int s = max(a[i][0], b[j][0]);
                int e = min(a[i][1], b[j][1]);
                ans.push_back({s,e});
            }
            
            if(i<a.size() && j<b.size() &&
               a[i][1] < b[j][1]){
                i++;
            }
            
            else if(i<a.size() && j<b.size() && 
                    a[i][1] > b[j][1])
                j++;
            else 
            {
                i++;
                j++;
            }   
        }
        return ans;
    }
};

// Time Complexity: O(m+n)          m = size of vector a
//                                  n = size of vector b
