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
    TreeNode* fun(TreeNode* node){
        if(node==NULL){
            return NULL;
        }
        
        TreeNode* lf = fun(node->left);
        TreeNode* rt = fun(node->right);
        
        TreeNode* temp = lf;
        
        if(temp==NULL){
            node->right = rt;
            return node;
        }
        
        while(temp->right){
            temp = temp->right;
        }
        
        node->left = NULL;
        temp->right = node;
        node->right = rt;
        
        return lf;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return fun(root);
    }
};