// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int dp[1001][1001];
    int ans = 0;
    
    int fun(int i, int j, string &a, string &b){
        
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(a[i]==b[j]){
            dp[i][j] = 1+fun(i-1,j-1,a,b);
        }
        else{
            dp[i][j] = 0;
        }
        
        fun(i-1,j,a,b);
        fun(i,j-1,a,b);
        
        ans = max(ans, dp[i][j]);
        return dp[i][j];
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(dp,-1,sizeof(dp));
        fun(n-1,m-1,S1,S2);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends