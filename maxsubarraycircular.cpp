class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        if(a.size()==0)
            return 0;
        if(a.size()==1)
            return a[0];
        int ans = INT_MIN;
        int sum=0;
        for(int i=0;i<a.size();i++){
            sum += a[i];
            ans = max(ans, sum);
            if(sum<0)
                sum=0;
        }
        
        int *rsum = new int[a.size()];
        rsum[a.size()-1] = a[a.size()-1];
        for(int i=a.size()-2 ; i>=0 ; i--)
            rsum[i] = rsum[i+1]+a[i];
        
        int *rmax = new int[a.size()];
        rmax[a.size()-1] = a[a.size()-1];
        for(int i=a.size()-2 ; i>=0 ; i--){
            rmax[i] = max(rsum[i], rmax[i+1]);
        }
        
        int lsum = 0;
        for(int i=0 ; i<a.size()-2 ; i++){
            lsum += a[i];
            ans = max(ans, rmax[i+2]+lsum);
        }
        return ans;
    }
};

// Used: Kadane's algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/