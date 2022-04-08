class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>>pq;
    int kk;
    
    KthLargest(int k, vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
 
        
        kk = k;
        
        for(int i=max(n-k,0);i<n;i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        
        if(pq.size()==kk-1){
            pq.push(val);
            
            return pq.top();
        }
        
        if(val>= pq.top()){
            
            pq.pop();
            pq.push(val);
            
        }
        
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */