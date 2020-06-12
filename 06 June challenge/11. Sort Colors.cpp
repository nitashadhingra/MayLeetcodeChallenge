// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/

class Solution {
public:
    void sortColors(vector<int>& nums) {     
        
        //          SORTING O(N^2)
        // for(int i = 0 ; i<nums.size()-1 ; i++){
        //     for(int j=i+1; j<nums.size() ; j++){
        //         if(nums[j]<nums[i])
        //             swap(nums[i], nums[j]);
        //     }
        // }
        
        //      TWO PASS O(N)
        // int r=0, w=0 , b=0 ;
        // for(int i=0 ; i<nums.size() ; i++){
        //     if(nums[i]==0)
        //         r++;
        //     else if(nums[i]==1)
        //         w++;
        //     else
        //         b++;
        // }
        // int i=0;
        // while(r--){
        //     nums[i++] = 0;
        // }
        // while(w--){
        //     nums[i++] = 1;
        // }
        // while(b--)
        //     nums[i++] = 2;
        
        
        //          ONE PASS O(N)
        int w = 0;
        int r = 0;
        int b = nums.size()-1;
        
        while(w <= b){
            
            if(nums[w] == 0){
                swap(nums[w], nums[r]);
                w++;
                r++;
            }
            
            else if(nums[w]==1)
                w++;
            
            else{
                swap(nums[w], nums[b]);
                b--;
            }
        }
        
    }
};