#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){

    int weapons, capacity, distance;
    cin >> weapons >> capacity >> distance;
    if(weapons <= capacity ){
        cout << max(0, weapons - distance);
    }else{
        int travelled = 0;
        while(weapons > capacity && travelled!=distance){
            int traverse = 1;
            while(traverse*capacity < weapons){
                traverse++;
            }
            int distance = ceil((double)capacity/traverse);
            int transferred = 0;
            while(traverse && weapons >=0){
                transferred = transferred + (min(capacity, weapons) - distance);
                traverse--;
                weapons = weapons - capacity;
            }
            travelled += distance;
            weapons = transferred;
        }
        cout << max(0, weapons - (distance - travelled));

    }
}