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
    TreeNode* helper(TreeNode* root, TreeNode* newNd){
        
        if(root==nullptr){
            return newNd;
        }
        
        if(root->val < newNd->val){
            root->right = helper(root->right, newNd);
        }
        else{
            
            root->left = helper(root->left, newNd);
        }
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* newNd = new TreeNode(val);
        
        return helper(root, newNd);
    }
};