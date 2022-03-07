class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>v;
        
        if(n==1){
            vector<int>t = {1};
            v.push_back(t);
            return v;
        }
        
        if(n==2){
            vector<int>t1= {1};
            v.push_back(t1);
            vector<int>t2= {1,1};
            v.push_back(t2);
            return v;
        }
                        
        vector<int>t1= {1};
        v.push_back(t1);
        vector<int>t2= {1,1};
        v.push_back(t2);
                    
        for(int i=2;i<n;i++){
            
            vector<int> t(i+1);
            
            int a=0,b=1;
            
            t[0] = 1;
            for(int j=1;j<i;j++){
                t[j] = v[i-1][a] + v[i-1][b];
                a++;
                b++;
            }
            t[i] = 1;
            
            v.push_back(t);
        }
        
        return v;
    }
};