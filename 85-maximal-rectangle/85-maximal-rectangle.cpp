class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> left(m,0), right(m,m-1), ht(m,0);
        
        int mxA = 0;
        
        for(int i=0;i<n;i++){
            
            int l_bd = 0, r_bd = m-1;
            
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]=='1'){
                    ht[j]++;
                    left[j] = max(left[j],l_bd);
                }
                else{
                    ht[j] = 0;
                    left[j] = 0;
                    l_bd = j+1;
                }
            }
            
            for(int j=m-1;j>=0;j--){
                
                if(matrix[i][j]=='1'){
                    right[j] = min(right[j],r_bd);
                }
                else{
                    right[j] = m-1;
                    r_bd = j - 1;
                }
            }
            
            for(int j=0;j<m;j++){
                mxA = max(mxA, (right[j]-left[j]+1)*ht[j]);
            }
        }
        
        return mxA;
    }
};