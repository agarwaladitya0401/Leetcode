



class Solution {
    
private:
    
    vector<Node*> all_nodes;
public:
    
    Solution(){
     all_nodes = vector<Node*>(101,NULL);
    }
    
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        
        if (all_nodes[node->val] != NULL)
            return all_nodes[node->val];
        
        Node* new_node = new Node(node->val, {});
        all_nodes[node->val] = new_node;
        
        for (auto &i: node->neighbors)
            new_node->neighbors.push_back(cloneGraph(i));
        
        return new_node; 
    }
};