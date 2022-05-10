class Solution {
public:
    
    int dp[13][10001];
    
    int fun(int i, int s, vector<int>&c, int n){
        
        if(s==0){
            return 0;
        }
        
        if(i>=n){
            return 10001;
        }
        
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        
        if(c[i]<=s){
            dp[i][s] = min(1+fun(i,s-c[i],c,n),fun(i+1,s,c,n));
        }
        else{
            dp[i][s] = fun(i+1,s,c,n);
        }
        
        return dp[i][s];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof(dp));
        
        int t = fun(0,amount,coins,coins.size());
        
        return t<=amount?t:-1;
    }
};