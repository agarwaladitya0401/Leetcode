class Solution {
public:
    bool isRobotBounded(string ins) {
        
        int a=0,b=0;
        int d[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
        int dir = 0;
        int len = ins.size();
        
        for(int i=0;i<ins.length();i++){
            
            if(ins[i]=='G'){
                a+=d[dir][0];
                b+=d[dir][1];
                 
                if((i+1)%len==0){
                   cout<<"i: "<<i<<" a: "<<a<<" b: "<<b<<endl;
                    if((a==0 and b==0) || dir!=0){
                        return 1;
                    }
               }
                
            }
            else if(ins[i]=='L'){
                dir++;
                dir%=4;
            }
            else{
                dir+=3;
                dir%=4;
            }           
        }
        
        if(a==0 and b==0 || dir!=0){
            return 1;
        }
        
        return 0;
    }
};