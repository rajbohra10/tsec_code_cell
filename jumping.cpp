#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s = "supercalifragilisticexpialidocious";
    string s = "antidisestablishmentarianism";
    int count = 0;
    for(int i=0; i<s.size()-1; i++){
        int a = s[i];
        int b = s[i+1];
        cout << a << " " << b << endl;
        if(a!=b)
        count += abs(b-a)-1 ;
    }
    cout << count  << endl;
    // 209 * 221
}