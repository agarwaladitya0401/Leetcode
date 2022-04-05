class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int l =0, s= 0;
        int ans = -1e5,sm=0;
        
        while(l<n){
            
           
            
            sm+=nums[l];
            
             ans = max(ans,sm);
            if(sm<0){
                sm = 0;
                // l++;
                // s=l;
            }
            l++;
             // ans = max(ans,sm);
            
        }
        
        return ans;
        
    }
};