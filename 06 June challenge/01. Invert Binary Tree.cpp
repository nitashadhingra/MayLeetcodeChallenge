// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/

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
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root)
            return root;
        stack <TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* f = s.top();
            s.pop();
            TreeNode* temp = f->left;
            f->left = f->right;
            f->right = temp;
            if(f->left)
                s.push(f->left);
            if(f->right)
                s.push(f->right);
        }
        return root;
    }
};

// Time Complexity: O(n)