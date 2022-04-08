class Solution {
public:
    
    map<string,bool>mp;
    
    bool fun(string s1, string s2){
        
        int n = s1.size();
        int m = s2.size();
        
        string key = s1 + " " + s2;
        
        
        
        if(mp.find(key)!=mp.end()){
            // cout<<"k:"<<key<<endl;
            return mp[key];
        }
        
        if(n!=m){
            // cout<<"k:"<<key<<endl;
            return mp[key] = false;
        }
        
        
        if(s1==s2){
            // cout<<"k:"<<key<<endl;
            return mp[key] = true;
        }
        
        if(n==1){
            // cout<<"k:"<<key<<endl;
            return mp[key] = false;
        }
        
        // cout<<"n"<<n<<endl;
        
        for(int k=1;k<=n-1;k++){
            
//             cout<<"s1ff:"<<s1.substr(0,k)<<endl;
//             cout<<"s2ff:"<<s2.substr(0,k)<<endl;
            
//             cout<<"s1ss:"<<s1.substr(k,n-k)<<endl;
//             cout<<"s2ss:"<<s2.substr(k,n-k)<<endl<<endl;
            
            if(fun(s1.substr(0,k),s2.substr(0,k)) and fun(s1.substr(k,n-k),s2.substr(k,n-k)))             {
                   return mp[key] = true;
            }
        }
        
        for(int k=1;k<=n-1;k++){
            
//             cout<<"s1f:"<<s1.substr(n-k,k)<<endl;
//             cout<<"s2f:"<<s2.substr(0,k)<<endl;
            
//             cout<<"s1s:"<<s1.substr(0,n-k)<<endl;
//             cout<<"s2s:"<<s2.substr(k,n-k)<<endl<<endl;
            
            if(fun(s1.substr(n-k,k),s2.substr(0,k)) and fun(s1.substr(0,n-k),s2.substr(k,n-k)))             {
                   return mp[key] = true;
            }
        }
        
        
            return mp[key] = false;
        
        
    }
    
    bool isScramble(string s1, string s2) {
        return fun(s1,s2);
    }
};