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
    TreeNode* del(TreeNode* root)
    {
        if(root -> right == NULL)
            return root -> left;
        else if(root -> left == NULL)
            return root -> right;
        
        TreeNode* curr = root -> right;
        
        while(curr -> left)
            curr = curr -> left;
        
        curr -> left = root -> left;

        return root -> right;
        
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL)
            return root;
        if(root -> val == key)
            return del(root);

        TreeNode* temp = root;

        while(temp)
        {
            if(temp -> val > key)
            {
                if(temp -> left && temp -> left -> val == key)
                {
                    temp -> left = del(temp -> left);
                    break;
                }
                else
                    temp = temp -> left;
            }
            else{
                if(temp -> right && temp -> right -> val == key)
                {
                    temp -> right = del(temp -> right);
                    break;
                }
                else
                    temp = temp -> right;
            }
        }

        return root;

        
    }
};