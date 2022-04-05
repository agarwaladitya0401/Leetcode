class Solution {
public:
    
    int dp[20][30];
    vector<int>pos;
    
    bool fun(int i, int j, int n, int m, char l, string &s, string &p){
        
        if(i==n and j==m){
            return 1;
        }
        else if(i>n or j>m or i<0 or j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(p[j]=='*'){
            if(p[j-1]=='.' or s[i]==p[j-1]){
                dp[i][j] = (fun(i+1,j,n,m,l,s,p) || fun(i+1,j+1,n,m,l,s,p) || fun(i,j+1,n,m,'-1',s,p) || fun(i-1,j+1,n,m,'-1',s,p));    
            }
            else{
                dp[i][j] = (fun(i-1,j+1,n,m,'-1',s,p) || fun(i,j+1,n,m,'-1',s,p));
            }
            
        }
        else if(p[j]=='.'){
            dp[i][j] = fun(i+1,j+1,n,m,'.',s,p);
        }
        else{
            if(s[i]==p[j]){
                l = p[j];
                dp[i][j] = fun(i+1,j+1,n,m,l,s,p);    
            }
            else{
                // auto nx = upper_bound(pos.begin(),pos.end(),j);
                
                if(j<m-1 and p[j+1]=='*'){
                    // int id = *nx;
                    // cout<<"id:"<<id<<"\n";
                    // l = p[id-1];
                    dp[i][j] = fun(i,j+2,n,m,'-1',s,p);
                }
                else{
                    dp[i][j] = 0;    
                }
                
            }
        }
            
            if(j<m-1 and p[j+1]=='*'){
                    dp[i][j] = (dp[i][j] || fun(i,j+2,n,m,'-1',s,p));
            }
        
        return dp[i][j];
        
    }
    
    bool isMatch(string s, string p) {
        
        
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int m = p.size();
        char l = '-1';
        for(int i=0;i<m;i++){
            if(p[i]=='*'){
                pos.push_back(i);
            }
        }
        return fun(0,0,n,m,l,s,p);
        
        
    }
};