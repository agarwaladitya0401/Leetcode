class Solution {
public:
    
    bool fun(int i, int j, int n, int m, string &s, string &p, vector<vector<int>>&dp){
        
        if(i==n and j==m){
            return 1;
        }
        
        if(i>n or j>m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==n and j<m){
            
            for(int jj=j;jj<m;jj++){
                if(p[jj]!='*'){
                    return 0;
                }
            }
            
            return 1;
        }
        
        if(p[j]=='?'){
            dp[i][j] = fun(i+1,j+1,n,m,s,p,dp);
        }
        else if(p[j]=='*'){
            dp[i][j] = (fun(i+1,j,n,m,s,p,dp) || fun(i,j+1,n,m,s,p,dp));
        }
        else{
            if(s[i]==p[j]){
                dp[i][j] = fun(i+1,j+1,n,m,s,p,dp);
            }
            else{
                dp[i][j] = 0;       
            }
        }
        
        // cout<<"i,j:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        return dp[i][j];
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         dp[i][j] = -1;
        //     }
        // }
                              
        return fun(0,0,n,m,s,p,dp);
    }
};