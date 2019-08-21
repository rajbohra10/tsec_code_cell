#include<iostream>
#include<vector>
#include<string>


using namespace std;
int main(){
    int sum = 0;
    for(int i=0; i<8; i++){
    string date;
    cin >> date;
    int day;
    int month;
    long long year = 0;
    day = stoi(date.substr(0, date.find("/"))); 
    date.erase(0, date.find("/") + 1);
    month = stoi(date.substr(0, date.find("/"))); 
    date.erase(0, date.find("/") + 1);
    while(date.size()!=0){
        string temp(1, date[0]); 
        year += stoi(temp);
        date.erase(0, 1);
        if(date.size() == 0) break;
        else year = year*10;
    }
    int start = (2*(year-1))%7;
    // cout << start << endl;
    cout << ((month - 1) * 31 + day)%7 + start - 1<< endl;
    sum += ((month - 1) * 31 + day)%7 + start - 1;
    // cout << 2*start << endl;
    }
    cout << sum << endl;
    
}