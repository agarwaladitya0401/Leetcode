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
    
    pair<int,pair<int,int>> isValid(TreeNode* root){
        
        int newMin = 0, newMax = 0;
        int boolL = 0, boolR = 0;
        
        if(root == NULL){
            return {1,{0,0}};
        }
        else if(root->left==NULL and root->right==NULL){
            return {1,{root->val,root->val}};
        }
        
        if(root->left and root->right){
            
            auto itL= isValid(root->left);
            boolL = itL.first;
            newMin = itL.second.second;
            
            auto itR= isValid(root->right);
            boolR = itR.first;
            newMax = itR.second.first; 
            
            if(root->val>itL.second.first and root->val<itR.second.second){
                
                cout<<"l1:"<<boolL<<" r1:"<<boolR<<endl;
                cout<<"lmin:"<<newMin<<" rmax:"<<newMax<<endl;
                
                newMin = min(newMin,root->val);
                newMax = max(newMax,root->val); 
                
                cout<<"lmin:"<<newMin<<" rmax:"<<newMax<<endl;
                return {(boolL & boolR),{newMax,newMin}};
            }
            else{
                return  {0,{newMax,newMin}};    
            }
            
            // return {(boolL & boolR),{newMax,newMin}};
        
        }
        else if(root->left){
            
            auto itL= isValid(root->left);
            boolL = itL.first;
            newMin = itL.second.second;
            
            if(root->val>itL.second.first){
                cout<<"l2:"<<boolL<<" r2:"<<boolR<<endl;
                cout<<"lmin:"<<newMin<<" rmax:"<<newMax<<endl;
                newMax = root->val;
                newMin = min(newMin,root->val);
                cout<<"lmin:"<<newMin<<" rmax:"<<newMax<<endl;
                return {boolL,{newMax,newMin}};
            }
            else{
                return  {0,{newMax,newMin}};    
            }
        }
        else if(root->right){
            auto itR= isValid(root->right);
            boolR = itR.first;
            newMax = itR.second.first; 
            
            if(root->val<itR.second.second){
                cout<<"l3:"<<boolL<<" r3:"<<boolR<<endl;
                cout<<"lmin:"<<newMin<<" rmax:"<<newMax<<endl;
                newMin = root->val;
                newMax = max(newMax,root->val);  
                cout<<"lmin:"<<newMin<<" rmax:"<<newMax<<endl;
                return {boolR,{newMax,newMin}};
            }
            else{
                return  {0,{newMax,newMin}};    
            }
        }
        
        
        
        return {1,{0,0}};
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return 1;
        }
        
        return isValid(root).first;
    }
};