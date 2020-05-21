// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<int> skipped;
    stack<int> s;
    StockSpanner() {
        return;
    }
    
    int next(int price) {
        int c=1;
        while(!s.empty() && s.top()<=price)
        {
            s.pop();
            c += skipped.top();
            skipped.pop();
        }
        s.push(price);
        skipped.push(c);
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 // Time Complexity: O(n)       n = number of calls to next()
 // Space Complexity: O(n)  
