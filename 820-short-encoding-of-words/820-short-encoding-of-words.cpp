
class trieNode{
    public:
    unordered_map<char,trieNode*>next;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        trieNode* root = new trieNode();
        
        vector<pair<trieNode *, int>>leaves;
            
        for(auto &word:words){
            
            trieNode* cur = root;
            bool fl = 0;
            
            for(int i=word.size();i>=0;i--){    
                
                fl = 0;
                
                // cout<<cur<<" "<<word[i]<<endl;
                // cout<<" bnc:"<<cur->next.count(word[i])<<endl;
                if(cur->next.count(word[i])==0) cur->next[word[i]] = new trieNode();
                else fl = 1;
                
                // cout<<" nc:"<<cur->next.count(word[i])<<"fl:"<<fl<<endl;
                cur = cur->next[word[i]];
            }
            
            // cout<<"afl:"<<fl<<endl;
            if (fl == 0){
                // cout<<"pursed"<<endl;
                leaves.push_back({cur,word.size()+1});
            }
        }
        
        int ans = 0;
        
        for(auto it:leaves){
            
            if(it.first->next.size()==0){
                ans+=it.second;
            }
        }
        
        return ans;
    }
};