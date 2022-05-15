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
    
    int fun(int &ans, int lvl, TreeNode* node, int &mxLvl){
        
        if(node==NULL)
            return 0;
        
        if(lvl>mxLvl){
            ans = node->val;
        }
        else if(lvl==mxLvl){
            ans += node->val;
        }
        
        mxLvl = max(mxLvl,lvl);
        
        fun(ans,lvl+1,node->left,mxLvl);
        fun(ans,lvl+1,node->right,mxLvl);
        
        return ans;
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0, mx = 0;
        return fun(ans,0,root,mx);
    }
};