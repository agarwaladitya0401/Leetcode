class Solution {
public:
    vector<string> ans;
    
    void fun(string s, int o, int n){
        if(n==0 or o<0 or o>n){
            return;
        }
        
        if(o==1 and n==1){
            s+=')';
            ans.push_back(s);
            return;
        }
        
        if(o>=1){
            s+='(';
            fun(s,o+1,n);
            s.pop_back();
            s+=')';
            fun(s,o-1,n-1);
        }
        else{
            s+='(';
            fun(s,o+1,n);
        }
        // cout<<s;
        return;
    }
    vector<string> generateParenthesis(int n) {
        fun("",0,n);
        return ans;
    }
};