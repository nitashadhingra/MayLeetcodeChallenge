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