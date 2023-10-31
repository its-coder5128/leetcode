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
    pair<int,int> solve(TreeNode* root)
    {
        if(root == NULL)
            return {0,0};

        auto left = solve(root -> left);
        auto right = solve(root -> right);

        int d = max(left.second + 1 + right.second,max(left.first,right.first));
        int h = max(left.second,right.second) + 1;

        return {d,h};

    }
    int diameterOfBinaryTree(TreeNode* root) {

        return solve(root).first-1;
        
    }
};