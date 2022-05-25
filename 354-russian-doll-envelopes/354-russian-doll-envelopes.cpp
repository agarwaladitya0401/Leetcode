class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int>ans;
        
        vector<pair<int,int>>env;
        
        int n = envelopes.size();
        
         for(int i=0;i<n;i++){
            int a = envelopes[i][0];
            int b = envelopes[i][1];
            env.push_back({a,b});
         }
        
        sort(env.begin(),env.end(),[](pair<int,int>a,pair<int,int>b){
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        });
        
        // int a = envelopes[0][0];
        // int b = envelopes[0][1];
        
        // ans.push_back(b);
        
        for(int i=0;i<n;i++){
            // a = envelopes[i][0];
            int b = env[i].second;
            // cout<<"ab:"<<a<<" "<<b<<endl;
            
            // int c = ans.back().first;
//             int d = ans.back();
            
//             if(d<b){
//                 ans.push_back(b);
//                 // cout<<"cd:"<<c<<" "<<d<<endl;
            
//             }
//             else{
//                 int s = 0, e = ans.size()-1;
                auto ele = lower_bound(ans.begin(),ans.end(),b);
                if(ele!=ans.end()){
                    *ele=b;
                }
                else{
                    ans.push_back(b);
                }
                
//                 while(s<=e){
//                     int m = (s+e)/2;
                    
//                     // int curr_a = ans[m].first;
//                     int curr_b = ans[m];
                    
//                     if(curr_b>=b){
//                         ele = m;
//                         e = m-1;
//                     }
//                     else{
//                         s = m+1;
//                     }
//                 }
//                 if(ele!=-1){
//                     // cout<<"fs:"<<ans[ele].first<<" "<<ans[ele].second<<endl;
//                     ans[ele] = b;
                    
//                 }
            // }
        }
        return ans.size();
    }
};