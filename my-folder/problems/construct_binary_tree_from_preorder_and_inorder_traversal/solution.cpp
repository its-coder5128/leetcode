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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int s,int e,int &index)
    {
        if(s > e)
        {
            return NULL;
        }


        TreeNode* temp = new TreeNode(preorder[index]);
        int x = s;
        while(x<=e)
        {
            if(inorder[x] == preorder[index])
                break;
            x++;
        }
        if(x>e)
            return NULL;
        index++;
        temp -> left = solve(preorder,inorder,s,x-1,index);
        temp -> right = solve(preorder,inorder,x+1,e,index);

        return temp;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s = 0;
        int e = preorder.size()-1;
        int index = 0;


        return solve(preorder,inorder,s,e,index);
        
    }
};