// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    void findkth(TreeNode* root, vector<int> &v, int k){
        if(root==NULL)
            return;
        findkth(root->left, v, k);
        v.push_back(root->val);
        if(v.size()==k)
            return;
        findkth(root->right, v, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        findkth(root, v, k);
        return v[k-1];
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
