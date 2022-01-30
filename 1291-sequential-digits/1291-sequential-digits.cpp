class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        int ans = 0;
        vector<int>v;
        
        int sl = ceil(log10(low));
        int el = ceil(log10(high));
        
        for(int i = sl; i<=el; i++){
            
            // if(i==el){
                
                int no = 0;
                int onlyOne = 0;
                int ld = 1;
                int len = i;
                
                while(len--){
                    no = no*10 + ld;
                    onlyOne = onlyOne*10 + 1;
                    ld++;
                }
                
                // if(no<=high){
                //     v.push_back(no);
                //     ans++;
                // }
            
                while(no <= high and (no%10 !=0)){
                    if(no>=low)
                    v.push_back(no);
                    ans++;
                    no += onlyOne;
                }
                
                
            // }
            // else{
            //     ans += (10-i);
            // }
        }
        
        
        return v;
        
        
    }
};