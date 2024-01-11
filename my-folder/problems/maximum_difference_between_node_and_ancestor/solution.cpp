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
    int solve(TreeNode* root,int high,int low)
    {
        if(root == NULL)
            return INT_MIN;
        
        int left = solve(root->left,max(high,root->val),min(low,root->val));
        int right = solve(root->right,max(high,root->val),min(low,root->val));

        return max(left,max(right,max(abs(root->val-low),abs(root->val-high))));
    }
    int maxAncestorDiff(TreeNode* root) {

        int left = solve(root->left,root->val,root->val);
        int right = solve(root->right,root->val,root->val);

        return max(left,right);
        
    }
};