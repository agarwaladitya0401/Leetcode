class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        
        for(auto i:ops){
            
            if(i=="+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                
                s.push(a);
                s.push(a+b);
                
                
            }
            else if(i=="D"){
                int a = s.top();
                s.pop();
                // int b = s.top();
                
                s.push(a);
                s.push(2*a);
            }
            else if(i=="C"){
                s.pop();
            }
            else{
                s.push(stoi(i));
            }
        }
        
        int sm = 0;
        
        while(s.size()){
            sm+=s.top();
            s.pop();
        }
        
        return sm;
    }
};