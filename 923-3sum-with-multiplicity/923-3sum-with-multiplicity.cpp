class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long int  a = 0;
        int m  = (1e9 + 7);
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        vector<int>uni;
        uni.push_back(arr[0]);
        
        
        long int freq[101] = {0};
        
        for(auto i:arr){
            if(uni.back()!=i){
                uni.push_back(i);
            }
            freq[i]++;
        }
        
        n = uni.size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                int sm = uni[i]+uni[j];
                int req = target - sm;
                
                if(req<uni[j] or req>100)
                    continue;
                
                // cout<<uni[i]<<" "<<uni[j]<<" "<<req<<"\n";
                // cout<<"a:"<<a<<endl;
                if(uni[i]==uni[j] and uni[j]==req){
                    a += ((freq[req])*(freq[req]-1)*(freq[req]-2))/6;
                }
                else if(uni[i]==uni[j]){
                    a += ((freq[uni[j]])*(freq[uni[j]]-1)*(freq[req]))/2;
                }
                else if(uni[j]==req){
                    a += ((freq[uni[j]])*(freq[uni[j]]-1)*(freq[uni[i]]))/2;
                }
                else{
                    a += (freq[uni[i]])*(freq[uni[j]])*(freq[req]);
                }
                // cout<<"a:"<<a<<endl;
                a %=m ;
            }
        }
        
        return a;
    }
};