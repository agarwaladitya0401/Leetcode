class Solution {
public:
    
    static bool compare(vector<int> a, vector<int>b){
        if(a[0]<b[0]){
            return 1;
        }
        else
        return 0;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        
        int sz = intervals.size();
        
        sort(intervals.begin(), intervals.end(), compare);
        
        for(int i=0;i<sz;i++){
            
            int s = intervals[i][0], e = intervals[i][1];
            
            while(i<sz and e>=intervals[i][0]){

                e = max(e,intervals[i][1]);
                i++;
            }
            i--;
            v.push_back({s,e});
        }
        
        return v;
    }
};