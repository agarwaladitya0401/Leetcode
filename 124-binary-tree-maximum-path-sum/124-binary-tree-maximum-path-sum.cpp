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
    int fun1(TreeNode* node){
        if(node==NULL)
            return 0;
        
        return max(node->val + max(fun1(node->left), fun1(node->right)),0);
    }
    
    int fun2(TreeNode* node){
        if(node==NULL)
            return INT_MIN;
        
        int a = (node->val + fun1(node->left) + fun1(node->right));
        int b = max(fun2(node->left), fun2(node->right));
        
        return max(a,b);
    }
    
    int maxPathSum(TreeNode* root) {
        return fun2(root);
    }
};