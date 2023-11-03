/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;

        if(p->val > q -> val)
            return lowestCommonAncestor(root,q,p);
        
        
        TreeNode* temp = root;

        while(temp)
        {
            if(temp -> val == q -> val || temp -> val == p -> val)
                return temp;
            if(temp -> val < q -> val && temp -> val > p->val)
                return temp;
            else if(temp -> val < q -> val && temp -> val < p->val)
                temp = temp -> right;
            else
                temp = temp -> left;
        }

        return temp;
        
    }
};