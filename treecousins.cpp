/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL || root->val==x || root->val==y)
            return false;
        TreeNode* x_parent = NULL;
        TreeNode* y_parent = NULL;
        queue<TreeNode*> q;
        q.push(root);
        int nodes_at_this_level = 1;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            nodes_at_this_level--;
            
            if(f->right){
                q.push(f->right);
                if(f->right->val==x)
                    x_parent = f;
                else if(f->right->val==y)
                    y_parent = f;
            }
            if(f->left){
                q.push(f->left);
                if(f->left->val==x)
                    x_parent = f;
                else if(f->left->val==y)
                    y_parent = f;
            }
            if(nodes_at_this_level == 0){
                if(x_parent || y_parent)
                    break;
                nodes_at_this_level = q.size();
            }
        }
        return x_parent && y_parent && x_parent!=y_parent;
    }
};

// Used: BFS
// Time Complexity: O(n)
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/