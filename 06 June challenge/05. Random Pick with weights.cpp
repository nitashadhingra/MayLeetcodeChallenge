// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/

#include<cstdlib>
class Solution {
public:
    vector<int> v;
    int size;
    int sum;
    Solution(vector<int>& w) {
        
        size = w.size();
        srand((unsigned)time(0));
        
        sum = 0; 
        for(int i=0 ; i<size ;i++) {
            sum += w[i];
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        return upper_bound( v.begin() , v.end() , rand() % sum ) - v.begin() ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// Time Complexity: O(n)