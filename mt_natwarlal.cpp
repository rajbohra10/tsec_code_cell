#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>> nums = {
        {6,5,4,3,2,1},
        {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21},
        {300,2,2,5,80,20,11,222,34,56,77,80,19,222,215,20,88,210,97,99,1000,1100,2500,212,290,111,122,133,700,712,850,90,0,20,25,35,50,70,222,1555,222,700,300,712,850,11,90,7,2,5,0,20,25,35,50,70,222,122},
        {111,1111,112,12,13,1,445,1000,2112,1221,90,80,5,7,8,9,190,200,212,567,777,899,123,22,45,77,8,9,10,233,221,34,222,190,80,70,35,32,12,0}
    };
    int total = 0;
    for(int i=0; i<nums.size(); i++){
        vector<int> piles = nums[i];
        int sum = 0;
        for(int j=0; j<piles.size(); j++){
            sum += piles[j];
        }
        cout << sum << endl;
        total += sum;
    }
    cout << total << endl;
}