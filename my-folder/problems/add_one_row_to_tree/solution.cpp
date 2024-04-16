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
    void solve(TreeNode* root, int val, int depth)
    {
        if(root == NULL)
            return;
        if(depth == 2)
        {
            
                TreeNode* newNode1 = new TreeNode(val);
                newNode1 -> left = root -> left;
                root -> left = newNode1;
            
            
                TreeNode* newNode2 = new TreeNode(val);
                newNode2 -> right = root -> right;
                root -> right = newNode2;
            
            return;
        }
        solve(root -> left,val,depth-1);
        solve(root -> right,val,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }

        solve(root,val,depth);

        return root;
    }
};