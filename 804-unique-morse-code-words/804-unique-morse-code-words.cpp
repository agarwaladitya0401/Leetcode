class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        // map<char,string>mp;
        
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        // for(int i=0;i<26;i++){
        //     mp[a+i] = arr[i];
        // }
        
        set<string>s;
        
        for(auto it:words){
            string temp = "";
            
            for(auto c:it){
                temp+=arr[c-'a'];
            }
            
            s.insert(temp);
        }
        
        return s.size();
    }
};