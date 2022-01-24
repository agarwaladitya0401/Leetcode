class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int t =0;
        
        for(auto i:word){
            if(i>='A' and i<='Z'){
                t++;
            }
        }
        
        int n = word.size();
        
        if(t == n or t == 0){
            return 1;
        }
        else if(t == 1 and word[0]>='A' and word[0]<='Z'){
            return 1;
        }
        
        return 0;
    }
};