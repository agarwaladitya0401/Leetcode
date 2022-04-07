class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it:stones){
            pq.push(it);
        }
    
    
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        int c = abs(a-b);
        
        if(c>0){
            pq.push(c);
        }
    }
    
    if(pq.size()){
        return pq.top();
    }
    
    return 0;
    }
};