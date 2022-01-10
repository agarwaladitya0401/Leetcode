class Solution {
public:
    string addBinary(string a, string b) {
        
        vector<int>v1,v2;
        
        for(auto i:a){
            v1.push_back(i-'0');
        }
        
        for(auto i:b){
            v2.push_back(i-'0');
        }
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        
        vector<int>ans;
        
        int i=0,c=0;
        
        while(i<v1.size() || i<v2.size()){
            
            int a=0,b=0;
            
            if(i<v1.size()){
                a = v1[i];    
            }
            
            if(i<v2.size()){
                b = v2[i];    
            }
            
            ans.push_back((c+a+b)%2);
            
            c = (c+a+b)/2;
            
            i++;
            
        }
        
        if(c!=0){
            // int temp = (c+a+b)%2;
            ans.push_back(c);
        }
        
         reverse(ans.begin(),ans.end());
        
        string tt = "";
        
        for(auto it:ans){
            
            char ch = it+'0';
            tt.push_back(ch);
        }
        
        return tt;
    }
};