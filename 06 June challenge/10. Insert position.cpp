// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size() && target>nums[i])
            i++;
        return i;
    }
};

// Time Complexity: O(n)