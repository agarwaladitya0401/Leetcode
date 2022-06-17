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
    int dp[1001][2][2];
    
    map<TreeNode*, int> mp;
    
    int id = 0;
    
    int fun(int pc, int nc, TreeNode* node){
        
        if(node==NULL){
            if(pc==0 and nc==1)
                return 1000;
            else if(pc==0 and nc==0)
                return 0;
            else
                return 0;
        }
        
        // cout<<"pc:"<<pc<<" nc:"<<nc<<" nodeval:"<<node->val<<endl;
        
        if(node->val==0){
            node->val = ++id;
        }
        
        int nid = node->val;
        
        if(dp[nid][pc][nc]!=-1){
            return dp[nid][pc][nc];
        }
        
        int temp = 1000;
        
        if(pc==1){
            if(nc==1){
               temp = min(2+fun(1,1,node->left)+fun(1,1,node->right), fun(1,0,node->left)+fun(1,0,node->right));
                temp = min(1+fun(1,0,node->left)+fun(1,1,node->right),temp);
                temp = min(1+fun(1,1,node->left)+fun(1,0,node->right),temp);
            }
            else{
               temp = min(2+fun(0,1,node->left)+fun(0,1,node->right), fun(0,0,node->left)+fun(0,0,node->right));
                temp = min(1+fun(0,0,node->left)+fun(0,1,node->right),temp);
                temp = min(1+fun(0,1,node->left)+fun(0,0,node->right),temp);
            }
        }
        else{
            
             if(nc==1){
               temp = min(2+fun(1,1,node->left)+fun(1,1,node->right), fun(1,0,node->left)+fun(1,0,node->right));
                temp = min(1+fun(1,0,node->left)+fun(1,1,node->right),temp);
                temp = min(1+fun(1,1,node->left)+fun(1,0,node->right),temp);
            }
            else{
               temp = 2+fun(0,1,node->left)+fun(0,1,node->right);
                temp = min(1+fun(0,0,node->left)+fun(0,1,node->right),temp);
                temp = min(1+fun(0,1,node->left)+fun(0,0,node->right),temp);
            }
        }
        
        return dp[nid][pc][nc] = temp;
        
    }
    
    int minCameraCover(TreeNode* root) {
        memset(dp,-1,sizeof(dp));   
        
        int temp = 1001;
        
        // temp = 2+fun(0,1,root->left)+fun(0,1,root->right);
        
        temp = min(1+fun(0,1,root),fun(0,0,root));
        
        // temp = min(1+fun(0,1,root->left)+fun(0,0,root->right),temp);
        
        return temp;
    }
};