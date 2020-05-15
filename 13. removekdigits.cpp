class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==0 || num.length()==0)
            return num;
        if(k>=num.length())
           return "0";
        stack<char> s;
        for(int i=0;i<num.length();i++){
            while(!s.empty() && k>0 && s.top()>num[i])
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k--)
            s.pop();
        string ans = "";
        while(!s.empty()){
            ans.insert(ans.begin(), s.top());
            s.pop();
        }
        while(ans[0]=='0' && ans.length()>1){
            ans.erase(ans.begin());
        }
        return ans;
    }
};

// Used: Greedy Approach
// Time Complexity: O(n+k)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/
