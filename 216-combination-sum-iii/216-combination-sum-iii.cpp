class Solution {
public:
    vector<vector<int>> ans;
    
    void fun(vector<int>temp, int k, int s, int srt){
        
        if(k==0 and s==0){
             ans.push_back(temp);
            return;
        }
        
        if(k<0 or s<0){
            return;
        }
        
        for(int i=srt;i<=9;i++){
            
            if(i<=s){
                temp.push_back(i);
                fun(temp,k-1,s-i,i+1);
                temp.pop_back();
            }
        }
        
        return;
    }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        
        fun({},k,n,1);
        return ans;
    }
};