class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            // cout<<"tt ans:"<<ans<<" i:"<<i<<" s[i]"<<s[i]<<endl;
            switch(s[i]){
                case 'I':
                    {
                        if(i+1<n and s[i+1]=='V'){
                            ans+=4;
                            i++;
                        }
                        else if(i+1<n and s[i+1]=='X'){
                            ans+=9;
                            i++;
                        }
                        else{
                            ans+=1;
                        }
                    }
                    break;
                
                
                case 'X':
                    {
                        if(i+1<n and s[i+1]=='L'){
                            ans+=40;
                            i++;
                        }
                        else if(i+1<n and s[i+1]=='C'){
                            ans+=90;
                            i++;
                        }
                        else{
                            ans+=10;
                        }
                    }
                    break;
                
                case 'C':
                    {
                        if(i+1<n and s[i+1]=='D'){
                            ans+=400;
                            i++;
                        }
                        else if(i+1<n and s[i+1]=='M'){
                            ans+=900;
                            i++;
                        }
                        else{
                            ans+=100;
                        }
                    }
                    break;
                case 'V':
                    ans+=5;
                    break;
                case 'L':{
                    // cout<<"ans:"<<ans<<" i:"<<i<<" s[i]"<<s[i]<<endl;
                    ans+=50;
                }
                    break;
                case 'D':
                    ans+=500;
                    break;
                case 'M':
                    ans+=1000;
                    break;
            }
        }
        return ans;
    }
};