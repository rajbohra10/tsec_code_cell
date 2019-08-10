#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums = {6, 120, 50};
    for(int i=0; i<nums.size(); i++){
        int n = nums[i];
        vector<int> nos(n);
        for(int j=0; j<n; j++){
            cin >> nos[j];
        }
        int total = 0;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(nos[j]!=nos[k]){
                    int ans = nos[j] & nos[k];
                    total += ans;
                }
            }
        }
        cout << total%101 << endl;
    }
}