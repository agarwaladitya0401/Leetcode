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
class BSTIterator {
public:
    int pointer = -1;
    vector<int>v;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        
        // if(root->left==NULL and root->right==NULL){
        //     v.push_back(root->val);
        // }
        // else{
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        // }
    }
    
    BSTIterator(TreeNode* root) {
        
        inorder(root);
    }
    
    int next() {
        pointer++;
        return v[pointer];
        
    }
    
    bool hasNext() {
        if(pointer+1<v.size()){
            return 1;
        }
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */