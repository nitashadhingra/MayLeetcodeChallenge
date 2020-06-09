// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0;
        for(int i=0;i<s.length();i++){
            bool p = false;
            for(int j=pos;j<t.length();j++){
                if(s[i]==t[j]){
                    pos = j+1;
                    p=true;
                    break;
                }
            }
            if(!p)
                return false;
        }
        return true;
    }
};

// Time Complexity: O(n^2)