class Solution {
public:
    
    vector<vector<int>> ans;
    
    void subset(int i, int n, vector<int>temp, vector<int> &nums){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        subset(i+1, n, temp, nums);
        temp.push_back(nums[i]);
        subset(i+1, n, temp, nums);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        subset(0,n,vector<int>(),nums);
        
        return ans;
    }
};