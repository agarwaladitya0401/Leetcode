class Solution {
public:
    vector<string> ans;
    
    void fun(int id, string d, int n, string tmp, vector<char>(&v)[10]){
        
        if(id==n){
            if(tmp!="") ans.push_back(tmp);
            return;
        }
        
        int dig = d[id]-'0';
        
        for(auto it:v[dig]){
            tmp.push_back(it);
            fun(id+1,d,n,tmp,v);
            tmp.pop_back();
        }
        
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<char>v[10];
        
        v[2]={'a','b','c'};
        v[3]={'d','e','f'};
        v[4]={'g','h','i'};
        v[5]={'j','k','l'};
        v[6]={'m','n','o'};
        v[7]={'p','q','r','s'};
        v[8]={'t','u','v'};
        v[9]={'w','x','y','z'};    
        
        fun(0,digits,digits.size(),"",v);
        
        return ans;
    }
};