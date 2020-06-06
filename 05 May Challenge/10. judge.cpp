class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0)
            return 1;
        set<int> st;
        unordered_map<int, int> judge;
        for(int i=0 ; i<trust.size() ; i++){
            st.insert(trust[i][0]);
            if(judge.find(trust[i][0]) != judge.end())
                judge.erase(trust[i][0]);
            judge[trust[i][1]]++;
        }
        for(auto i=judge.begin() ; i!=judge.end() ; i++){
            if(i->second==n-1 && st.find(i->first)==st.end())
                return i->first;
        }
        return -1;
    }
};

// Time Complexity: O(n)       n = length of trust vector
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/
