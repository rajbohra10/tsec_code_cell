#include <iostream>
#include<vector>
typedef long long ll;
using namespace std;
bool magical(ll num, ll p){
    ll reverseNum = 0;
    ll n = num;
    while(n > 0){
        reverseNum = reverseNum + n%10;
        n = n/10;
        if(n > 0){
            reverseNum *= 10;
        }
    }
    return (abs(reverseNum - num) % p == 0);
}
int main(){
    ll sum = 0;
    for(int i=0; i<4; i++){
    ll start;
    ll end;
    ll p;
    cin >> start >> end >> p;
    ll count = 0;
    for(ll i=start; i<=end; i++){
        if(magical(i, p)){
            count++;
        }
    }
    cout << count << endl;
    sum += count;
    }
    cout << sum << endl;
}