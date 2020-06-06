// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0)
            return;
        for(int i=0; i<s.size()/2 ; i++)
            swap(s[i], s[s.size()-1-i]);
    }
};

// Time Complexity : O(n)
// Space Complexity: in-place