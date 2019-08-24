#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
    
    vector<ll> nums = {
        5,
        500,
        5000000000
    };
    ll result = 1;
    for(int i=0; i<nums.size(); i++){
        ll n = nums[i];
        ll ans = 0;
        if(n%3 == 0){
            ans = 18 * (n/3);
        }else{
            while(n%3 != 0){
                n = n-1;
            }
            ans = 18*(n/3);
            if(nums[i] - n == 1){
                ans = ans + 1;
            }else if(nums[i] - n == 2){
                ans = ans + 9;
            }
        }
        result = (result * ans%1000007)%1000007;
        cout << ans << endl;
    }
    cout << result << endl;
}