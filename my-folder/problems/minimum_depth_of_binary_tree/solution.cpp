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
    pair<int,int> solve(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<int,int> p=make_pair(0,0);
            return p;
        }

        pair<int,int> left=solve(root -> left);
        pair<int,int> right=solve(root -> right);

        pair<int,int> node;

        int height = max(left.first,right.first) + 1;
        int minHeight;
        if(left.first == 0 || right.first == 0)
        {
            if(left.first == 0 && right.first != 0)
                minHeight=right.second + 1 ;
            else if(left.first != 0 && right.first == 0)
                minHeight=left.second + 1 ;
            else    
                minHeight = height;
        }
        else{
            minHeight = min(left.second,right.second) + 1;
        }

        return {height,minHeight};

    }
public:
    int minDepth(TreeNode* root) {
        return solve(root).second;
    }
};