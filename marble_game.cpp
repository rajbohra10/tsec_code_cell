#include <iostream>
#include <vector>

using namespace std;

int main(){
    int sum = 0;
    vector<int> nums = {22, 45, 26, 75};
    // vector<int> nums = {6};
    for(int no=0; no<nums.size(); no++){

    int n;
    n = nums[no];
    vector<int> dp(n+1);
    vector<vector<int>> picks = {{}, {}, {}};
    dp[0] = -1;
    dp[1] = 10;
    dp[2] = 10;
    dp[3] = 20;
    int player = 1;
    for(int i=4; i<=n; i++){
        if(i%3 == 0){
            if(dp[i - 1] == 20 || dp[i - 2] == 20){
                dp[i] = 10;
            }else{
                dp[i] = 20;
            }
        }else if((i - 1)%3 == 0){
            if(dp[i-1] == 20 || dp[i-3] == 20){
                dp[i] = 10;
            }else{
                dp[i] = 20;
            }
        }else if((i - 2)%3 == 0){
            if(dp[i - 1] == 20 || dp[i - 2] == 20 || dp[i - 3] == 20){
                dp[i] = 10;
            }else{
                dp[i] = 20;
            }
        }
    }
    cout << dp[n]  << endl;
    if(dp[n] == 10) sum+= 1;
    else sum += 2;
    }
    cout << sum << endl;
}
    