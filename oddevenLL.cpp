/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        ListNode* even = h2;
        while(h1 && h2){
            h1->next = h2->next;
            if(h1->next)
                h2->next = h1->next->next;
            else
                break;
            h1 = h1->next;
            h2 = h2->next;
        }
        h1->next = even;
        return head;
    }
};

// Time Complexity:  O(n)
// Space Complexity: O(1)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/