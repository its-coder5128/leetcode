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
    void solve(TreeNode* root,vector<int>& arr,int& ans)
    {
        if(!root)
            return;
        if(root -> left == NULL && root -> right == NULL)
        {
            arr[root->val]++;
            int cnt = 0;
            for(int i = 0;i<10;i++)
            {
                if(arr[i] & 1)
                    cnt++;
            }
            if(cnt<2)
                ans++;
            
            arr[root->val]--;
            return;
        }

        arr[root->val]++;
        solve(root->left,arr,ans);
        solve(root->right,arr,ans);
        arr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {

        int ans = 0;

        vector<int> arr(10,0);
        solve(root,arr,ans);

        return ans;
        
    }
};