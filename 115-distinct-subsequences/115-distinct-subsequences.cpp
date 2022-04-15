class Solution {
public:
    int dp[1001][1001];
    
    int val(int i, int j, string &s, string &t){
        
        
        if(j==-1){
            return 1;
        }
        
        if(i==-1){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            dp[i][j] = val(i-1,j-1,s,t) + val(i-1,j,s,t);
        }
        else
            dp[i][j] = val(i-1,j,s,t);
        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        
        int ans = 0;
        
        int n = s.size();
        int m = t.size();
        
        return val(n-1,m-1,s,t);
 
        
        return ans;
    }
};