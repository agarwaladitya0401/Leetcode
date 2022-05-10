class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int s =0;
        
        for(auto it:nums){
            s+=it;
        }
        
        if(s%2==1){
            return 0;
        }
        
        s = s/2;
        
        int dp[s+1];
        
        
        memset(dp,0,sizeof(dp));
        
        dp[0] = 1;
        
        for(int i=0;i<n;i++){
            
            for(int j=s;j>=0;j--){
                
                if(nums[i]<=j)
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
        
        return dp[s];
    }
};