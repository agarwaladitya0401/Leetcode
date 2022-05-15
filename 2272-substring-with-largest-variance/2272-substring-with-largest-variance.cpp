class Solution {
public:
    int largestVariance(string s) {
        map<char,int>mp;
        
        for(auto it:s){
            mp[it]++;
        }
        
        int ans = 0;
        
        for(char i='a';i<='z';i++){
            
            for(char j='a';j<='z';j++){

                int freqB = mp[j];
                int currA = 0;
                int currB = 0;
                
                if(i==j || mp[i]==0 || mp[j]==0) continue;
                
                for(auto it:s){
                    if(it==i){
                        currA++;
                    }
                    else if(it==j){
                        currB++;
                        freqB--;
                    }
                    
                    if(currB>0)
                    ans = max(ans,currA-currB);
                    
                    if(currA-currB<0 and freqB>=1){
                        currA = 0;
                        currB = 0;
                    }
                }
            }    
        }
        return ans;
    }
};