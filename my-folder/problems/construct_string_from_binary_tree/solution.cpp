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
    void preOrdered(TreeNode* root,string &ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(root -> left == NULL && root -> right == NULL)
        {
            ans += to_string(root->val);
            return;
        }

        ans += to_string(root->val);

        ans.push_back('(');
        preOrdered(root->left,ans);
        ans.push_back(')');
        
        ans.push_back('(');
        preOrdered(root->right,ans);
        if(ans.back() == '(')
            ans.pop_back();
        else
            ans.push_back(')');

        return;
    }
    string tree2str(TreeNode* root) {

        string ans = "";

        preOrdered(root,ans);

        return ans;
        
    }
};