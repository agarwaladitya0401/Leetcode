class Solution {
public:
    
    int atmost(int k, vector<int>&nums){
        
        int n = nums.size();        
        int i=0,j=0;
        
        map<int,int>mp;
        
        int ans = 0;
        
        int uni_cnt = 0;
        
        for(;j<n;j++){
            
            if(mp[nums[j]]==0){
                uni_cnt++;
            } 
            
            mp[nums[j]]++;
            
            if(uni_cnt<=k){
                ans+=(j-i+1);
            }
            else{
                while(uni_cnt>k){
                    
                    mp[nums[i]]--;
                    
                    if(mp[nums[i]]==0){
                        uni_cnt--;
                    }
                    i++;
                }
                ans+=(j-i+1);
            }
            
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        return atmost(k,nums) - atmost(k-1,nums);
    }
};