class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>s;
        
        int n = nums.size();
        
        int s3 = INT_MIN;
            
        for(int i=n-1;i>=0;i--){
            
            int c = nums[i];
            
            while(s.size() and c>s.top()){
                s3 = max(s3,s.top());
                s.pop();
                
            }
            
            // if(s.size()){
            //     cout<<"s "<<s.top()<<endl;
            // }
            // cout<<"s3"<<s3<<endl;
            // cout<<"c"<<c<<endl;
            
            if( s3>c){
            //     if(s.size()){
            //     cout<<"s "<<s.top()<<endl;
            // }
            // cout<<"s3"<<s3<<endl;
            // cout<<"c"<<c<<endl;
                return true;
            }
            
            s.push(c);
            
        }
        
        return false;
    }
};