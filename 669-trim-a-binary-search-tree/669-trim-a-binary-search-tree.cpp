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

	if(root == nullptr) 
		return nullptr;

	// Why use a queue of double pointers ?
	//
	// Queue stores a copy of the (single) pointer to
	//  current node, thus when we modify (single) pointer
	//  to point to nullptr, we modify a copy and the original 
	//  remains unaffected.
	//
	// When using a double pointer to current node,
	//  queue still stores a copy of the double pointer.
	//  However, both the copy and the original reference same 
	//  memory location and thereby when we can modify the value 
	//  stored in deferenced double pointer, we get the desired effect. 
	queue<TreeNode**> todo{{&root}};

	while(!todo.empty()) {

		TreeNode** node = todo.front();
		todo.pop();

		// Check if current node is greater than
		//  lower bound.
		//
		//  If not, replace current node with its
		//   right subtree.
		while ( (*node)->right
			 && (*node)->val < low) 
		{
			// Before replacing current node with its
			//  right subtree, it might me useful
			//  to release allocated memory for current 
			//  and its left subtree.
			//
			// This might be a good point to get further
			//  clarifications from the interviewer.
			*node = (*node)->right;
		}

		// If node value is still less than lower bound
		//  we must mark the node null.
		//
		// WHY? Because it has no right child
		//  and all nodes (if any) in left subtree will
		//  be smaller than current node (BST property) and 
		//  must be trimmed.
		if ( (*node)->val < low ) 
		{
			*node = nullptr; 
			continue;
		}

		// Check if current node is smaller than
		//  upper bound.
		//
		//  If not, replace current node with its
		//   left subtree.            
		while ( (*node)->left
			 && (*node)->val > high) 
		{
			*node = (*node)->left;
		}

		// If node value is still greater than upper bound
		//  we must mark the node null.
		//
		// WHY? Because it has no left child
		//  and all nodes (if any) in right subtree will
		//  be greater than current node (BST property) and 
		//  must be trimmed.
		if ( (*node)->val > high ) 
		{
			*node = nullptr; 
			continue;
		}

		// If current node is within bounds, queue its children (if any)
		if (!((*node)->val < low || (*node)->val > high) ) 
		{
			if( (*node)->left != nullptr ) 
				todo.push( &(*node)->left );

			if( (*node)->right != nullptr ) 
				todo.push( &(*node)->right );
		}
		// Otherwise queue current node; it would be trimmed
		// next time it is visited
		else
		{
			todo.push(node);
		}
	}

	// return root of trimmed binary search tree
	return root;
}
};