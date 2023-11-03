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
    bool solve(TreeNode* root, int k,unordered_map<int,int> &m)
    {
        if(root == NULL)
            return false;
        
        if(m[k-root->val])
            return true;
        
        m[root->val] = 1;

        bool left = solve(root->left,k,m);
        bool right = solve(root->right,k,m);

        return right||left;
    }
    bool findTarget(TreeNode* root, int k) {

        unordered_map<int,int> m;

        return solve(root,k,m);
        
    }
};