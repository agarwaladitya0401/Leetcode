class Solution {
public:
    int maxArea(vector<int>& h) {
        
        vector<int>v,id;
        
        int n = h.size();
        
        v.push_back(h[0]);
        id.push_back(0);
        
        int mx = 0;
        for(int i=1;i<n;i++){
            
            int lw = 0, hi = id.size()-1;
            
            int ans = hi;
            
            while(lw<=hi){
                
                int md = (lw+hi)/2;
                
                int idx = id[md];
                
                int ht = h[idx];
                
                if(ht>=h[i]){
                    ans = md;
                    hi = md-1;
                }
                else{
                    lw = md+1;
                }
            }    
            
            int idx = id[ans];
            int ht = h[idx];
            mx = max(mx, min(ht,h[i])*(i-idx));
            
            int l = v.size()-1;
            
            if(v.back()<h[i]){
                v.push_back(h[i]);
                id.push_back(i);
            }
            
        }
        reverse(h.begin(),h.end());
        int f_a = mx;
        mx = 0;
        
        vector<int>v1,id1;
        
        v1.push_back(h[0]);
        id1.push_back(0);
        
        for(int i=1;i<n;i++){
            // cout<<"i:"<<i<<" "<<h[i]<<"\n";
            int lw = 0, hi = id1.size()-1;
            
            int ans = hi;
            
            while(lw<=hi){
                
                int md = (lw+hi)/2;
                
                int idx = id1[md];
                
                int ht = h[idx];
                
                if(ht>=h[i]){
                    ans = md;
                    hi = md-1;
                }
                else{
                    lw = md+1;
                }
            }    
            
            // cout<<"a:"<<ans<<"\n";
            int idx = id1[ans];
            int ht = h[idx];
        
            int t = min(ht,h[i])*(i-idx);
            // cout<<"i:"<<i<<" "<<h[i]<<"\n";
            // cout<<"idx:"<<idx<<"\n";
            // cout<<"s "<<v1.size()<<" "<<id1.size();
            // cout<<"ht:"<<ht<<"\n";
            mx = max(mx, t);
            
            
            if(v1.back()<h[i]){
                v1.push_back(h[i]);
                id1.push_back(i);
            }
            
        }
        
        return max(f_a, mx);
    }
};