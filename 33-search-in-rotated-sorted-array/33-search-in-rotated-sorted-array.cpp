class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int ans = -1;
        int lw = 0, hg = n-1;
        int r = 0;
        
        if(nums[n-1]<nums[0]){
            r = 1;
        }
        
        if(r){
            
            int l = 0, h = n-1;
            
            while(l<=h){
                int md = (l+h)/2;
                
                if(nums[md]>nums[n-1]){
                    ans = md;
                    l = md+1;
                }
                else{
                    h = md-1;
                }
            }
            
            // int fa = -1;
            // cout<<"ans"<<ans<<endl;
            if(target>=nums[0]){
                hg = ans;
            }
            else{
                lw = ans+1;
            }
        }
        
        // cout<<hg<<" "<<lw;
        
        int fa = -1;
        
        while(lw<=hg){
            int md = (lw+hg)/2;
            
            
            if(nums[md]==target){
                return md;
            }
            
            if(nums[md]>target){
                // ans = md;
                hg = md-1;
            }
            else{
                lw = md+1;
            }
        }
        
        return -1;
    }
};