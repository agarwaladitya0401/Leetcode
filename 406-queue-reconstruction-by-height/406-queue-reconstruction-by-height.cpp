class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),[](vector<int>a,vector<int>b){
            return (a[0]>b[0] || (a[0]==b[0]?a[1]<b[1]:0));
        });
        
        int n = people.size();
        
        vector<vector<int>>s;
        
        for(auto ppl:people){
            
            s.insert(s.begin()+ppl[1],ppl);
        }
        
        return s;
    }
};