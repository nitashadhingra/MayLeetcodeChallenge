// https://leetcode.com/problems/permutation-in-string/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> v(26);
        for(int j=0 ; j<s1.length() ; j++){
            v[s1[j]-'a']++;
            v[s2[j]-'a']--;
        }
        int i=0;
        while(true){
            int j=0;
            for(;j<26;j++){
                if(v[j]!=0)
                    break;
            }
            if(j==26)
                return true;
            if(i>=s2.length()-s1.length())
                break;
            v[s2[i]-'a']++;
            v[s2[i+s1.length()]-'a']--;
            i++;
        }
        return false;
    }
};

// Time Complexity: O(l1 + 26*(l2-l1))
// Space Complexity: O(1)
