class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0;
        
        int mi = INT_MAX;
        
        for(auto i:prices){
            mi = min(mi, i);
            
            ans = max(ans, i-mi);
            
        }
        
        return ans;
    }
};