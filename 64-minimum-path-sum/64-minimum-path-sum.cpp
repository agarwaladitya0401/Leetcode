class Solution {
public:
      int dp[201][201];   
    int sum(int i, int j, int n, int m, vector<vector<int>>& ob){
        
         if(i>=n or j>=m){
            return INT_MAX;
        }
        
        if(i==n-1 and j==m-1){
            return dp[i][j] = ob[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = ob[i][j] + min(sum(i+1,j,n,m,ob),sum(i,j+1,n,m,ob));
    }
    
    int minPathSum(vector<vector<int>>& ob) {
        memset(dp,-1,sizeof(dp));
        int n = ob.size();
        int m = ob[0].size();
        return sum(0,0,n,m, ob);
    }
};