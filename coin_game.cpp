#include<iostream> 
#include<cmath>
#include<vector>
using namespace std; 
typedef long long ll;
ll highestPowerof2(ll n) 
{ 
    ll p = (ll)log2(n); 
    // cout << p << endl;
    return (ll)pow(2, p); 
} 

int main() 
{ 
    vector<ll> nums = {10, 100, 1000000, 1000000000, 12345654321, 9999999999999999};
    ll sum = 0;
	for(int i=0; i<nums.size(); i++){
        ll n = nums[i];
        // cout << highestPowerof2(n) << endl; 
        sum += highestPowerof2(n);
    }
    cout << sum%1000000007 << endl;
	return 0; 
} 
