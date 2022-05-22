/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Node* hnd = new Node();
        
        // hnd->val = node->val;
        
        if(node==NULL){
            return NULL;
        }
        
        stack<Node*>stk;
        
        stk.push(node);
        
        map<int,Node*>mp;
        
        while(stk.size()){
            Node* nd = stk.top();
            stk.pop();
                
            int vl = nd->val;
            
            auto vec = nd->neighbors;
            
            if(mp.find(vl)==mp.end()){
                Node* nnd = new Node();
                nnd->val = nd->val;
                
                mp[vl] = nnd;
                
                for(auto it:vec){
                    int vl = it->val;
                    
                    if(mp.find(vl)==mp.end()){
                        Node* neighN = new Node(vl);
                        mp[vl] = neighN;
                        nnd->neighbors.push_back(neighN);
                        stk.push(it);
                    }
                    else{
                        Node* neighN = mp[vl];
                        nnd->neighbors.push_back(neighN);
                    }
                }
            }
            else{
                Node* nnd = mp[vl];
                // nnd->val = nd->val;
                
                // mp[vl] = nnd;
                
                for(auto it:vec){
                    int vl = it->val;
                    
                    if(mp.find(vl)==mp.end()){
                        Node* neighN = new Node(vl);
                        mp[vl] = neighN;
                        nnd->neighbors.push_back(neighN);
                        stk.push(it);
                    }
                    else{
                        Node* neighN = mp[vl];
                        nnd->neighbors.push_back(neighN);
                    }
                }
            }
            
        }
        
        return mp[node->val];
    }
};





