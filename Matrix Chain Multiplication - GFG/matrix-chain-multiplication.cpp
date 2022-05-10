// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[101][101];
    
    int fun(int i, int j, int n, int arr[]){
        
        if(j==i+1){
            return dp[i][j] = 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        dp[i][j] = INT_MAX;
        
        for(int k=i+1;k<j;k++){
            dp[i][j] = min(dp[i][j],fun(i,k,n,arr)+fun(k,j,n,arr)+arr[i]*arr[k]*arr[j]);
        }
        
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        
        return fun(0,N-1,N,arr);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends