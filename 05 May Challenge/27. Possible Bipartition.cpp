// https://leetcode.com/problems/possible-bipartition/
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/

class Solution {
    unordered_map<int, vector<int>> mp;
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.size() == 0)
            return true;
        
        int color[n+1];
        memset(color,-1,sizeof(color));
        for(int i=0; i<dislikes.size(); i++){
            mp[dislikes[i][0]].push_back(dislikes[i][1]);
            mp[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        queue<int> q;
        for(auto  j=mp.begin() ; j!=mp.end() ; j++){
            if(color[j->first] == -1){
                color[j->first] = 1;
                q.push(j->first);
            }
            while(!q.empty()){
                int f  = q.front();
                q.pop();
                auto i = mp.find(f);
                for(int j = 0 ; j < i->second.size() ; j++){
                    if(color[i->second[j]] == -1){
                        if(color[i->first]==1)
                            color[i->second[j]] = 2;
                        else
                            color[i->second[j]] = 1;
                        q.push(i->second[j]);
                    } 
                    else if(color[i->first] == color[i->second[j]])
                        return false;
                }
            }
        }
        return true;
    }
};

// Used: DFS
// Time Complexity: O(N+E)
// Space Complexity: O(N+E)