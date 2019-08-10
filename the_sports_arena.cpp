#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> prices = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    vector<int> nums = {10 , 256 , 511 , 4097 , 8194};
    vector<int> dp(8195);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 1;
    for(int i=5; i<=8194; i++){
        int minimum = INT_MAX;
        for(int j=0; j<prices.size(); j++){
            if(i-prices[j] >= 0){
                // cout << i << " " << prices[j] << endl;
                dp[i] = min(minimum, dp[i-prices[j]] + 1);
            }
        }
        // cout << "value : " << dp[i] << endl; 
    }
    int result = 1;
    for(int i=0; i<nums.size(); i++){
        result = result*dp[nums[i]];
    }
    cout << result << endl;
}
