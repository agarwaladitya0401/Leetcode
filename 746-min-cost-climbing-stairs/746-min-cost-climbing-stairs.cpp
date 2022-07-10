class Solution {
public:
    
    int dp[1001];
    
    int fun(int n, int i, vector<int>& cost){
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        dp[i] = min(fun(n,i+1,cost),fun(n,i+2,cost))+cost[i];
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        
        return min(fun(n,0,cost),fun(n,1,cost));
    }
};