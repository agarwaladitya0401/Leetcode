class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = words.size();
        int wl = words[0].size();
        
        unordered_map<string,int>temp,freq;
        
        for(auto it:words){
            freq[it]++;
        }
        
        vector<int>ans;
        
        int sl = s.size();
        
        for(int i=0;i+wl*n<=sl;i++){
            
            temp = freq;
            // cout<<"foo f:"<<temp["foo"]<<endl;
            int found = 0;
            string tempString = "";
            
//             cout<<"i:"<<i<<endl;
            
            for(int j=i;j<i+wl*n;j++){
                
                tempString += s[j];
                
                // cout<<"j:"<<j<<endl;
                
                if(tempString.size()==wl){
                    // cout<<"ts: "<<tempString<<endl;
                    if(temp[tempString]>0){
                        temp[tempString]--;
                        tempString = "";
                        found++;
                    }
                    else{
                        break;
                    }
                }
            }
            
            if(found==n){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};