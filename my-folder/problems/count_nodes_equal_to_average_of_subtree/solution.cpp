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
private:
    int result = 0;
    pair<int, int> sumTree(TreeNode* node) {
        if(node == nullptr) {
            return {0, 0};
        }
        
        if(!node->left && !node->right) {
            result++;
            return {node->val, 1};
        }

        auto left = sumTree(node->left);
        auto right = sumTree(node->right);

        if((left.first + right.first + node->val) / (1 + left.second + right.second) == node->val) {
            result++;
        }

        return {left.first+right.first + node->val, 1 + left.second + right.second};

    }    
public:
    int averageOfSubtree(TreeNode* root) {
        sumTree(root);
        return result;
    }
};