/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    stack<NestedInteger>node;
        
    NestedIterator(vector<NestedInteger> &nL) {
        int sz = nL.size();
        for(int i=sz-1;i>=0;i--){
            node.push(nL[i]);
        }
    }
    
    int next() {
        
        int t = node.top().getInteger();
        node.pop();
        return t;
    }
    
    bool hasNext() {
       
        while(node.size()){
            auto curr = node.top();
            
            if(curr.isInteger()){
                return true;
            }
            
            node.pop();
            
            vector<NestedInteger> &temp = curr.getList();
            
            int sz = temp.size();
            
            for(int i=sz-1;i>=0;i--){
                node.push(temp[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */