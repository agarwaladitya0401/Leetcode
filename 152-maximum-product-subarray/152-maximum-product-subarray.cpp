class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
        int n = nums.size();
        
        int p1 = nums[0], p2 = nums[0], res = nums[0];
        
        for(int i=1;i<n;i++){
            
            int temp = max({nums[i],p1*nums[i],p2*nums[i]});
            p2 = min({nums[i],p1*nums[i],p2*nums[i]});
            
            p1 = temp;
            
            res = max({res,p1,p2});
            
        }
        
        return res;
    }
};