class Solution {
public:
    int dp[10001];
    bool fun(vector<int>&a, int i, int n){
        if(i==n-1){
            return 1;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int go = min(a[i],n-i);
        
        for(int j=1;j<=go;j++){
            
            if(fun(a,i+j,n)){
                return dp[i] = 1;
            }
        }
        
        return dp[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return fun(nums, 0, n);
    }
};