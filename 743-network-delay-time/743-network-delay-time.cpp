class Solution {
public:
    
    // int dp[101][101];
    
    int nodeTime(int i, int t, vector<vector<int>>& edges, vector<vector<int>>& time, vector<int> &vis){
        
        if(vis[i]!=-1 and t>=vis[i]){
            return vis[i];
        }
        
        vis[i] = t;
        
        int childTime = 0;
        
        for(auto it:edges[i]){
            int tmp = time[i][it];
            childTime = max(childTime, nodeTime(it,t+tmp,edges,time,vis));    
        }
        
        
        // return dp[i][t] = max(t,childTime);
        return max(t,childTime);
        
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>v(n+1,-1);
        
        vector<vector<int>>time(n+1,vector<int>(n+1,0)),edges(n+1);
        
        for(auto v:times){
            time[v[0]][v[1]] = v[2];
            edges[v[0]].push_back(v[1]);
        }
        
        nodeTime(k,0,edges,time,v);
        int t = 0;
        int vis_n = 0;
        
        for(auto it:v){
            if(it!=-1){
                vis_n++;
                t = max(t,it); 
            }
        }
        
        return vis_n==n?t:-1;
    }
};