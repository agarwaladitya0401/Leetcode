class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        int lx = 0, ly = 0;
        
        ans[0][0] = 1;
        
        int r1 = 0, r2 = n-1, c1 = 0, c2 = n-1;
        
        while(r2>=r1 and c2>=c1){
            
            for(int i=c1;i<=c2;i++){
                
                if(ans[r1][i]==0){
                    ans[r1][i] = ans[r1][i-1]+1;
                }
            }
            r1++;
            
            for(int i=r1;i<=r2;i++){
                
                if(ans[i][c2]==0){
                    ans[i][c2] = ans[i-1][c2]+1;
                }
            }
            c2--;
            
             for(int i=c2;i>=c1;i--){
                
                if(ans[r2][i]==0){
                    ans[r2][i] = ans[r2][i+1]+1;
                }
            }
            r2--;
            
            for(int i=r2;i>=r1;i--){
                
                if(ans[i][c1]==0){
                    ans[i][c1] = ans[i+1][c1]+1;
                }
            }
            c1++;
        }
        
        return ans;
    }
};