class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        pair<int,int> nbr[8] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int l=0,d=0;
                
                for(auto it:nbr){
                    
                    int a = it.first;
                    int b = it.second;
                    
                    int ni = i+a;
                    int nj = j+b;
                    
                    if(ni>=0 and ni<n and nj>=0 and nj<m){
                        
                        if((board[ni][nj] & 1)==1){
                            l++;
                        }
                        else{
                            d++;
                        }
                    }
                }
                    
                    int ca = 0;
                    
                    if(board[i][j]==1){
                        if(l<2){
                            ca = 0;        
                        }
                        else if(l==3 or l==2){
                            ca = 1;
                        }
                        else{
                            ca = 0;
                        }
                    }
                    else{
                        if(l==3){
                            ca = 1;
                        }
                    }
                    // cout<<"i,j:"<<i<<" "<<j<<endl;
                    // cout<<"ca "<<ca<<endl;
                    // cout<<board[i][j]<<endl;
                    board[i][j] = ca<<1 | board[i][j];
                    
                    // cout<<"fb:"<<board[i][j]<<endl;
                
                
            }
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                board[i][j] >>= 1; 
            }
        
        return;
    }
};