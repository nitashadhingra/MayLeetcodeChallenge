// https://leetcode.com/problems/contiguous-array/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int c = 0;
        int len = 0;
        unordered_map<int, int> mp;
        mp.insert(make_pair(c, -1));
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==1)
                c++;
            else
                c--;
            if(mp.find(c) != mp.end())
                len = max(len, i-mp[c]);
            else
                mp[c] = i;
        }
        return len;
    }
};

// Used: HashMap
// Time Complexity: O(n)