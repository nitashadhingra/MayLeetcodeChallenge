// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        vector<int> in(numCourses,0);
        queue<int> q;
        //make graph
        for(auto& p:prerequisites){
            g[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        // Kahns algorithm
        for(int i=0 ; i<in.size() ; i++) 
            if(in[i]==0) 
                q.push(i);  
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto& u : g[f]){
                --in[u];
                if(in[u] == 0)
                    q.push(u);
            }
        }
		
        for(int i=0 ; i<in.size() ; i++) 
            if(in[i]!=0)
                return false;
        return true;
    }
};

// Used: Kahn's algorithm
// Time Complexity: O(V+E)