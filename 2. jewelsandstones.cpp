class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char,greater<int> > st(J.begin(),J.end());
        int ans=0;
        for(int i=0;i<S.length();i++){
            if(st.find(S[i])!=st.end())
                ans++;
        }
        return ans;
    }
};

// Used a set for jewels
// Time Complexity: O(n)    n=length of string of stones
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/
