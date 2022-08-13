class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
        int n = nums.size();
        
//         int p1 = nums[0], p2 = nums[0], res = nums[0];
        
//         for(int i=1;i<n;i++){
            
//             int temp = max({nums[i],p1*nums[i],p2*nums[i]});
//             p2 = min({nums[i],p1*nums[i],p2*nums[i]});
            
//             p1 = temp;
            
//             res = max({res,p1,p2});
            
//         }
        
//         return res;
        
        int ng = 0;
        int ps = 0;
        for(auto it:nums){
            if(it<0){
                ng++;
            }
            else if(it>0){
                ps++;
            }
        }
        
        long long int ans = nums[0];
        long long int i = 0, j = 0, p = 1;
        
        while(j<n){
            
            
            if(nums[j]==0){
                if(p<0){
                    while(p<0 and i<j){
                        p/=nums[i];
                        
                        cout<<"1p:"<<p<<endl;
                        i++;
                        if(i<j)
                        ans = max(ans,p);                        
                        cout<<"ans2 "<<ans<<endl;
                    }
                    
                }
                
                i = j+1;
                ans = max(ans,0LL);
                p = 1;
                cout<<"ans21 "<<ans<<" p:"<<p<<" i:"<<i<<endl;
                // j++;
            }
            else{
                cout<<"p:"<<p<<endl;
                p *= nums[j];
                ans = max(ans,p);
                cout<<"ans1 "<<ans<<endl;
            }
            
            j++;
        }
        
        while(p<0 and i<j){
            p/=nums[i];
            i++;
            if(i<j)
            ans = max(ans,p);
            cout<<"ans3 "<<ans<<endl;
        }
        
            ans = max(ans,(long long int)*max_element(nums.begin(),nums.end()));
            cout<<"ans4 "<<ans<<endl;
        
        
        return ans;
 
    }
};