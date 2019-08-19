#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main(){
    int sum = 0;
    for(int no=0; no<6; no++){

    
    int n;
    cin >> n;
    vector<int> length(3);
    for(int i=0; i<3; i++){
        cin >> length[i];
    }
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            if(i - length[j] >= 0 ){
                dp[i] = max(dp[i], dp[i - length[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    sum += dp[n];
    }
}