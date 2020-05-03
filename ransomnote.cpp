class Solution {
public:
    bool canConstruct(string r, string m) {
        if(r.length()>m.length())
            return false;
        map<char, int> mp;
        for(int i=0 ; i<m.length() ; i++){
            mp[m[i]]++;
        }
        for(int i=0 ; i<r.length() ; i++){
            mp[r[i]]--;
        }
        for(int i=0;i<mp.size();i++){
            if(mp[i]<0)
                return false;
        }
        return true;
    }
};

// Used Hashmap
// Time Complexity: O(n)    n=length of the string of magazine letters
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/