class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int s = 0;
        int e = nums.size()-1;
        int m = s+(e-1)/2;
        while(s<=e){
            m = s + (e-s)/2;
            if((m==0 && nums[m]!=nums[m+1]) || (m==nums.size()-1 && nums[m]!=nums[m-1]))
                return nums[m];
            
            if((m-s)%2 == 0){
                if(nums[m]==nums[m+1])
                    s = m+2;
                else if(nums[m]==nums[m-1])
                    e = m-2;
                else
                    return nums[m];
            }
            else{
                if(nums[m]==nums[m+1])
                    e = m-1;
                else if(nums[m]==nums[m-1])
                    s = m+1;
                else
                    return nums[m];
            }
        }
        return nums[m];
    }
};

// Used: Binary Search
// Time Complexity: O(logn)
// Space Complexity: O(1)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/