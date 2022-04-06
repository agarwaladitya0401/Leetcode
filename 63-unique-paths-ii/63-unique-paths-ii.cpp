class Solution {
public:
    int dp[101][101];   
    int ways(int i, int j, int n, int m, vector<vector<int>>& ob){
        
         if(i>=n or j>=m){
            return 0;
        }
        
        if(ob[i][j]==1){
            return dp[i][j] = 0;
        }
        
        if(i==n-1 and j==m-1){
            return dp[i][j] = 1;
        }
        
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = ways(i+1,j,n,m,ob) + ways(i,j+1,n,m,ob);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        memset(dp,-1,sizeof(dp));
        int n = ob.size();
        int m = ob[0].size();
        return ways(0,0,n,m, ob);
    }
};