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
    void solve(TreeNode* root,unordered_map<int,int> &m,int &maxi)
    {
        if(root == NULL)
            return;

        solve(root->left,m,maxi);
        maxi = max(maxi,++m[root->val]);
        solve(root->right,m,maxi);
    }
    vector<int> findMode(TreeNode* root) {

        unordered_map<int,int> m;

        int maxi = INT_MIN;
        solve(root,m,maxi);

        vector<int> ans;

        for(auto i:m)
        {
            if(maxi == i.second)
                ans.push_back(i.first);
        }

        return ans;
        
    }
};