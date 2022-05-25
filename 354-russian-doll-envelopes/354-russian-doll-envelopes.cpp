class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        vector<pair<int,int>>es;
        
        for(auto it:en){
            int a = it[0];
            int b = it[1];
            
            es.push_back({a,b});
        }
        
        sort(es.begin(), es.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);});
        vector<int> dp;
        for (auto e : es)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e.second);
            if (iter == dp.end())
                dp.push_back(e.second);
            else if (e.second < *iter)
                *iter = e.second;
        }
        return dp.size();
    }
};