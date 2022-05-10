class Solution {
public:
    
    int dp[1001][1001];
    
    int fun(int i, int j, string &a, string &b, int n1, int n2){
        
        if(i>=n1 or j>=n2){
            
            dp[i][j] = 0;
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(a[i]==b[j]){
            dp[i][j] = 1 + fun(i+1,j+1,a,b,n1,n2);
        }
        else{
            dp[i][j] = max(fun(i,j+1,a,b,n1,n2),fun(i+1,j,a,b,n1,n2));
        }
        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp,-1,sizeof(dp));
        
        return fun(0,0,text1,text2,text1.size(),text2.size());
        
        // return dp[0][0];
        
    }
};