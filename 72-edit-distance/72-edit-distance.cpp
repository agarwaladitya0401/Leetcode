class Solution {
public:
    
    int fun(int i, int j, int n1, int n2, string &a, string &b, vector<vector<int>>&dp){
        
        if(i>=n1 and j>=n2){
            return 0;
        }
        
        if(i<n1 and j>=n2){
            return n1-i;
        }
        
        if(i>=n1 and j<n2){
            return n2-j;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(a[i]==b[j]){
            dp[i][j] = fun(i+1,j+1,n1,n2,a,b,dp);
        }
        else{
            dp[i][j] = 1+min({fun(i+1,j,n1,n2,a,b,dp), fun(i+1,j+1,n1,n2,a,b,dp), fun(i,j+1,n1,n2,a,b,dp)});
        }
        
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return fun(0,0,n,m,word1,word2,dp);
    }
};