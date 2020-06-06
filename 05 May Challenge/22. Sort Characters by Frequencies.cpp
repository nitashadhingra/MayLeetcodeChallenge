// https://leetcode.com/problems/sort-characters-by-frequency/
//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/

class Solution {
public:
    string frequencySort(string s) {
        if(s.length()==0)
            return "";
        unordered_map<char, int> mp;
        for(int i=0 ; i<s.length() ; i++)
            mp[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        while(!mp.empty()){
            auto i = mp.begin();
            pq.push(make_pair(i->second, i->first));
            mp.erase(i->first);
        }
               
        string ans;
        while(!pq.empty()){
            ans.insert(ans.end()-ans.begin(), pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Time Complexity: O(n)        n = length of input string
// Space Complexity: O(n)
