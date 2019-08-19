#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(){
    int sum = 0;
    for(int i=0; i<5; i++){

    
        int temp;
        cin >> temp;
        priority_queue<int> pq;
        while(temp!=-1){
            pq.push(temp);
            cin >> temp;
        }
        int n = pq.size();
        if(n == 0) return 0;
        if(n == 1) return pq.top();
        while(pq.size()!=1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a-b);
        }
        
        sum += pq.top();
    }
    cout << sum << endl;
}