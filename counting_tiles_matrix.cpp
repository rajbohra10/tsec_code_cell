#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
const ull mod = 1000000007;
ull multiply(ull M[3][3], ull F[3][3]){
    ull ans[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[i][j] = 0;
            for(int k=0; k<3; k++)
            ans[i][j] += M[i][k]*F[k][j];
            // ans[i][j] = ans[i][j]%mod;
             
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
        M[i][j] = ans[i][j];
    }
    return 0;
}
ull power(ull M[3][3], ull n){
    ull F[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    if(n==1)
        return 1;
    else{
        power(M, n/2);
        multiply(M, M);
        if(n%2==1){
            multiply(M, F);
        }
    }
    return 1;
} 
ull solve(ull n){
    ull M[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    power(M, n-3);
    return (M[0][0]*4 + M[0][1]*2 + M[0][2]*1);
}

int main(){
    ull sum = 0;
    vector<ull> nums = {10, 100, 1000000, 1000000000, 12345654321, 9999999999999999};
    for(int i=0; i<nums.size(); i++){
        ull n = nums[i];
        sum = sum + solve(n);
    }
    // ull n = 1000000;
    // ans: 391582466
    cout << sum%mod << endl;
    return 0;
}