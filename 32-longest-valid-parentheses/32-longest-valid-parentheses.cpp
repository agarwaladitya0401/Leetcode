class Solution {
public:
    int longestValidParentheses(string s) {
        int o = 0;
        int st = 0, l=0;
        int ans = 0;
        int n = s.size();
        
        while(l<n){
            
            
            if(s[l]=='('){
                o++;
                l++;
            }
            else{
                
                if(o>0){
                    o--;
                    l++;
                }
                else{
                    l++;
                    st = l;
                }
            }
            
            if(o==0){
                ans = max(ans, l-st);
            }
        }
        int c = 0;
        st = n-1, l=n-1;
        while(st>0){
            
            
            if(s[st]==')'){
                c++;
                st--;
            }
            else{
                
                if(c>0){
                    c--;
                    st--;
                }
                else{
                    st--;
                    l = st;
                }
            }
            
            if(c==0){
                ans = max(ans, l-st);
            }
        }
        return ans;
    }
};