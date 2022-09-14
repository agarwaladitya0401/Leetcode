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
    
    int ans = 0;
    
    void fun(TreeNode* root, int arr[]){
        
        if(root==NULL)
            return;
        
        arr[root->val]++;
        
        if(!root->left and !root->right){
            int e=0,o=0;
            
            for(int i=1;i<=9;i++){
                arr[i]%2?o++:e++;
            }
            
            if(o<=1 and o+e>0){
                ans++;
            }
        }
        else{
            fun(root->left, arr);
            fun(root->right, arr);
        }
        arr[root->val]--;
        
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int arr[10];
        
        memset(arr,0,sizeof(arr));
        
        fun(root, arr);
        
        return ans;
    }
};