class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length())
            return ans;
        
        int scount[26] = {0};
        int pcount[26] = {0};
        for(int i=0;i<p.length();i++){
            scount[s[i]-'a']++;
            pcount[p[i]-'a']++;
        }
        
        
        int i=0;
        while(1){
            int j=0 ;
            for(; j<26 ; j++){
                if(scount[j]!=pcount[j])
                    break;
            }
            if(j==26)
                ans.push_back(i);
            if(i>=s.length()-p.length())
                break;
            scount[s[i]-'a']--;
            scount[s[i+p.length()]-'a']++;
            i++;
        }
        return ans;
    }
};

// Time Complexity: O(n)        n = length of string s
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/
