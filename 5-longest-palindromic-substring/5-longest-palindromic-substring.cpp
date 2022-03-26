class Solution {
public:
    
    int dp[1001][1001];
    
    bool isPalin(int i, int j, string &s){
        
        if(i>=j){
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==s[j])
            dp[i][j] = isPalin(i+1, j-1, s);
        else
            dp[i][j] = 0;
    
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=s.size();i>=0;i--){
            for(int j=0;j+i-1<s.size();j++){
                
                if(isPalin(j,i+j-1,s)){
                    return s.substr(j,i);
                }
            }
        }
        
        return "";
    }
};