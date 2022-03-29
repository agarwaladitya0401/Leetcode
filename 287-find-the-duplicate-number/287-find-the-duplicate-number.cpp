class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            
            int id = abs(nums[i]);
            
            if(nums[id-1]<0){
                return abs(nums[i]);
            }
            
            nums[id-1]*=-1;
        }
        
        return -1;
    }
};