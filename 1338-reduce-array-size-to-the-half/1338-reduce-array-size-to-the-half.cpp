class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int>mp;
        
        vector<int>v(*max_element(arr.begin(),arr.end())+1,0);
        
        for(auto it:arr){
            v[it]++;
        }
        
        sort(v.rbegin(),v.rend());
        
        int ans = 0;
        
        int n = arr.size();
        
        int freq = 0;
        
        for(auto it:v){
            
            freq += it;
            if(it!=0)
            ans++;
            // cout<<freq<<" "<<it<<endl;
            // cout<<ans<<endl;
            
            if(freq>= (n/2))
                break;
        }
        
        return ans;
    }
};