    
int dp[100001];

vector<int>v;

bool pre = [](){

    dp[1] = 1;
    
    for(int i=1;i*i<100001;i++){
        v.push_back(i*i);

    }


    for(int i=2;i<100001;i++){

        dp[i] = -1;

        int fl = 1;
        for(auto x:v){

            if(x>i){
                break;
            }

            if(dp[i-x]==0){

                dp[i] = 1;
                fl  =0;
                break;
            }
        }

        if(fl){
            dp[i] = 0;
        }

    }
        return true;
    }();

class Solution {
public:
    
    bool winnerSquareGame(int n) {
        
        // pre();
        
        if(dp[n]==1){
            return 1;
        }
        else{
            return 0;
        }
    }
};