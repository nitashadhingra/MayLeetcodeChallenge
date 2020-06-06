class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 1;
        for(int i = 1 ; i<nums.size() ; i++){
            if(maj == nums[i])
                count++;
            else 
                count--;
            if(count == 0){
                maj = nums[i];
                count++;
            }
        }
        return maj;
    }
};

// Space Complexity: O(1)
// Time Complexity: O(n)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/
