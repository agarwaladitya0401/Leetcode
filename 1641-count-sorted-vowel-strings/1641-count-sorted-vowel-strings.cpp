class Solution {
public:
    
    int dp[51][6];
    
    int fun(int i, int j, int n){
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==n-1 or j==4){
            return dp[i][j] = 1;
        }
        
        dp[i][j] = 0;
        
        for(int id=j;id<5;id++){
            dp[i][j] += fun(i+1,id,n);
        }
        
        return dp[i][j];
        
    }
    int countVowelStrings(int n) {
        
        int ans = 0;
        
        memset(dp,-1, sizeof(dp));
        
        ans = fun(0,0,n)+fun(0,1,n)+fun(0,2,n)+fun(0,3,n)+fun(0,4,n);
        
        return ans;
    }
};