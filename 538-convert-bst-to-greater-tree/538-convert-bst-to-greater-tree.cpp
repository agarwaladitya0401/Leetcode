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
    
    int sum(TreeNode **node, int incr){
        
        if(*node==NULL){
            return 0;
        }
        
        int a = (*node)->val;
        
        int incrRoot = sum(&(*node)->right, incr);
        (*node)->val += incrRoot+incr;
        int b = sum(&(*node)->left,(*node)->val);
        
        return a+b+incrRoot;
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        sum(&root,0);
        return root;
    }
};