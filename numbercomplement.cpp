class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;
        while(num){
            if(num%2 == 0)
                ans += pow(2,i);
            i++;
            num=num/2;
        }
        return ans;
    }
};

// Time Complexity: O(logn)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/