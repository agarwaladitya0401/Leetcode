class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int mx = 0;
        
        int st=0,l=0;
        
        map<int,int>ch;
        
        int n = s.size();
        
        if(n==0){
            return 0;
        }
        
        for(;l<n;l++){
            
            ch[s[l]-'a']++;
            
            if(ch[s[l]-'a']>1){
                while(ch[s[l]-'a']>1){
                    ch[s[st]-'a']--;
                    st++;
                }
                mx = max(mx, l-st+1);
            }   
            else{
                mx = max(mx, l-st+1);
            }
        }
        
        return mx;
    }
};