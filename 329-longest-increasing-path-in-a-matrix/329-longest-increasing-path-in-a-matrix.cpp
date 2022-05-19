class Solution {
public:
    
    int dp[201][201];
    
    int fun(int p, int i, int j, int n ,int m, vector<vector<int>>& matrix){
        
        if(i<0 or j<0 or i>=n or j>=m or p>=matrix[i][j]){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = 1;
        int curr_ele = matrix[i][j];
        
        int a = fun(curr_ele, i+1,j, n, m, matrix);
        int b = fun(curr_ele, i,j+1, n, m, matrix);
        int c = fun(curr_ele, i-1,j, n, m, matrix);
        int d = fun(curr_ele, i,j-1, n, m, matrix);
        
        a = max(a,b);
        c = max(c,d);
        
        ans += max(a,c);
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int curr_ele = matrix[i][j];
                ans = max(ans,fun(curr_ele, i-1,j, n, m, matrix)+1);
                ans = max(ans,fun(curr_ele, i+1,j, n, m, matrix)+1);
                ans = max(ans,fun(curr_ele, i,j+1, n, m, matrix)+1);
                ans = max(ans,fun(curr_ele, i,j-1, n, m, matrix)+1);
            }
        }
        return ans;
    }
};