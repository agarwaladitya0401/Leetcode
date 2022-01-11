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
    
    int evaluate(TreeNode* root, int val){
        
        if(root == NULL){
            return 0;
        }
        
        val*=2;
             
        if(root->val == 1){
            val+=1;
        }
        
        if(root->left==NULL and root->right==NULL){
            // cout<<"r: "<<root->val<<"val: "<<val<<"\n";
            return val;
        }
        
        return (evaluate(root->left,val) + evaluate(root->right,val));
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        
        return evaluate(root, 0);
    }
};