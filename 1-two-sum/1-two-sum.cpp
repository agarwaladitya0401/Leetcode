class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        
        vector<int> ans ;
        unordered_map<int,pair<int,int>> mp;
        int n = a.size();
        
        for(int i=0;i<n;i++){
            
            int freq = mp[a[i]].first;
            // cout<<a[i]<<endl;
            // cout<<freq<<endl;
            mp[a[i]] = { ++freq , i};
            // cout<<a[i]<<endl;
            // cout<<mp[a[i]].first<<endl;
        }
        
      
        for(int i=0;i<n;i++){
            
            int val = t - a[i] ;
             int freq = mp[val].first ;
            
            // cout<<a[i]<<endl;
            // cout<<freq<<endl<<endl;
            
            if(a[i]==val && freq<=1){
                
                continue ;
            }
                       
            if(mp[val].first != 0 ){
                
                // cout<<"fff"<<val<<"\n";
                ans.push_back(i);
                auto it = mp[val];
                int idx = it.second ;
                ans.push_back(idx);
                                
                break;
            }
            
        }
        
        return ans ;
    }
};