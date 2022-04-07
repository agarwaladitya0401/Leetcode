class Solution {
public:
    
    // see this explanation:https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution/175299
    
 //    we start from the first row, and move downward;
 // * height[i] record the current number of countinous '1' in column i;
 // * left[i] record the left most index j which satisfies that for any index k from j to  i, height[k] >= height[i];
 // * right[i] record the right most index j which satifies that for any index k from i to  j, height[k] >= height[i];
 // * by understanding the definition, we can easily figure out we need to update maxArea with value (height[i] * (right[i] - left[i] + 1));
    
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