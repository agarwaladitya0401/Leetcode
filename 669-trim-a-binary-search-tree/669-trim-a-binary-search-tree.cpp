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
    TreeNode* fun(TreeNode* root, int l, int h){
        
        if(root == NULL){
            return NULL;
        }
        
        if(root->val >= l and root->val <= h){
            root->left = fun(root->left, l, h);
            root->right = fun(root->right, l, h);
            return root;
        }
        
        if(root->val<l){
            root->right = fun(root->right, l, h);
            return root->right;
        }
        
        if(root->val>h){
            root->left = fun(root->left, l, h);
            return root->left;
        }
        
        return NULL;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* head = fun(root, low, high);;
        
            return head;
    }
};