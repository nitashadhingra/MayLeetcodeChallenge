class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};

// Used Hashmap
// Time Complexity: O(n)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/
