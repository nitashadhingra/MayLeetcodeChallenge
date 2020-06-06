// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/

#include<cmath>
class Solution {
    
public:
    static bool fn(vector<int>a, vector<int> b){
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        
        int n = people.size();
        vector<vector<int>> ans(n);
        if(n==0)
            return ans;
        
        sort(people.begin(), people.end(), fn);
        
        bool placed[n];
        memset(placed, false, sizeof(placed));
        
        for(int i=n-1 ; i>=0 ; i--){
            int j = people[i][1];
            int k = 0;
            while(k<j){
                if( placed[k] && ans[k][0]<people[i][0]){
                    j++;
                }
                k++;
            }
            while(j<n && placed[j])
                j++;
            ans[j] = people[i];
            placed[j] = true;
        }
        
        return ans;
    }
    
};

// Time Complexity: O(n^2)