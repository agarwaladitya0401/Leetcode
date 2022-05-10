class Solution {
public:
    
    int fun(int i, int m, int n, vector<vector<int>>&v, int sz, vector<vector<vector<int>>>&dp){
        
        // cout<<"i:"<<i<<endl;
        // cout<<"m:"<<m<<endl;
        // cout<<"n:"<<n<<endl;
        
        if(i>=sz or m<0 or n<0){
            return 0;
        }
        
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        
        if(v[i][0]>m or v[i][1]>n){
            dp[i][m][n] = fun(i+1,m,n,v,sz,dp);
        }
        else{
            
            dp[i][m][n] = max(fun(i+1,m,n,v,sz,dp), 1+fun(i+1,m-v[i][0],n-v[i][1],v,sz,dp));
        }
        // cout<<endl;
        // cout<<"i:"<<i<<endl;
        // cout<<"m:"<<m<<endl;
        // cout<<"n:"<<n<<endl;
        // cout<<"dp:"<<dp[i][m][n]<<endl;
        return dp[i][m][n];
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        
        vector<vector<int>>v(sz,vector<int>(2,0));
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        int i = 0;
        for(auto s:strs){
            
            for(auto d:s){
                if(d=='0'){
                    v[i][0]++;
                }
                else{
                    v[i][1]++;
                }
            }
            i++;
        }
        
        return fun(0,m,n,v,sz,dp);
        
    }
};