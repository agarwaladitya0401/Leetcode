class Solution {
public:
    int ways(int i, int j, int n, int m){
        
        if(i==n-1 and j==m-1){
            return 1;
        }
        
        if(i>=n or j>=m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = ways(i+1,j,n,m) + ways(i,j+1,n,m);
    }
    int dp[101][101];
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return ways(0,0,m,n);
    }
};