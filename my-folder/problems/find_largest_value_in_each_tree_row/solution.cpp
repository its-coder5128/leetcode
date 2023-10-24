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
    vector<int> largestValues(TreeNode* root) {

        if(root == NULL)
            return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int n = q.size(),maxi = INT_MIN;

        while(!q.empty())
        {
            TreeNode* node  = q.front();
            q.pop();

            maxi = max(maxi,node->val);


            if(node -> left)
            {
                q.push(node -> left);
            } 
            if(node -> right)
            {
                q.push(node -> right);
            } 
            if( --n == 0)
            {
                ans.push_back(maxi);
                maxi = INT_MIN;
                n = q.size();
            }
        }

        return ans;
        
    }
};