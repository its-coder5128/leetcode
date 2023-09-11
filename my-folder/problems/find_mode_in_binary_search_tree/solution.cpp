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
   void inorder(TreeNode* root,vector<int>&opt){
       if(!root)return;
       inorder(root->left,opt);
       opt.push_back(root->val);
       inorder(root->right,opt);
   }
    vector<int> findMode(TreeNode* root) {
        if(root==NULL)return {};
        vector<int> res;
        inorder(root,res);
        unordered_map<int,int> m;
        for(int i=0;i<res.size();i++){
            m[res[i]]++;
        } 
        int maxfreq=INT_MIN;
        vector<int> modes;
        for (const auto& pair : m) {
            if (pair.second > maxfreq) {
                maxfreq = pair.second;
                modes.clear();
                modes.push_back(pair.first);
            } else if (pair.second == maxfreq) {
                modes.push_back(pair.first);
            }
        }

        return modes;
 
    }
    
};