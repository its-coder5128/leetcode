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
    int solve(TreeNode* root,int &maxi)
    {
        if(root == NULL)
            return 0;
        
        int left = max(solve(root->left,maxi),0);
        int right = max(solve(root->right,maxi),0);

        int sum = root -> val + left + right;

        maxi = max(maxi,sum);

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        solve(root,maxi);

        return maxi;
        
    }
};