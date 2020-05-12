class Solution {
public:
    
    void fill(vector<vector<int>>& image, 
              int r, int c, int newc, int color ) {
        
        if(image[r][c]==color){
            image[r][c]=newc;
            if(r-1>=0)
                fill(image,r-1,c,newc, color);
            if(c-1>=0)
                fill(image,r,c-1,newc, color);
            if(r+1<image.size())
                fill(image,r+1,c,newc, color);
            if(c+1<image[0].size())
                fill(image,r,c+1,newc, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int sr, int sc, int newColor ) {
        
        if(image.size()==0)
            return image;
        int color = image[sr][sc];
        if(color!=newColor)
            fill(image, sr,sc,newColor, color);
        return image;
    }   
};

// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/
