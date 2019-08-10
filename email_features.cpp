#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    set<string> str;
    string s1;
    vector<string> strs = {"tseccodecell@gmail.com", "code@tsec.com" ,"tsec@gmail.com",  "tseccode.cell@gmail.com", "tsec@tsec.codecell.com", "tsec+codecell@gmail.com", "tse.ccodecell@gmail.com" ,"cod.e@tsec.com" ,"tsec.codecell@gmail.com" ,"code@tsec.com" ,"tseccodecell+tsec@gmail.com" ,"code+cell@tsec.com" ,"tseccode+cell@gmail.com" ,"codecell@tsec.com" ,"tsec.codecell@gmail.com" ,"tsec@tseccodecell.com" ,"code+cell@tsec.com" ,"tsec@gmail.com" ,"tsec+codecell@gmail.com" ,"tsec@tseccodecell.com" ,"tsec+codecell@gmail.com" ,"code@tsec+code.com" ,"tsec@tseccodecell.com"};
    for(int i=0; i<strs.size(); i++){
        s1 = strs[i];
        int index = s1.find('@');
        int dotIndex = s1.find('.');
        while(dotIndex!=-1 && dotIndex<index){
            s1.erase(dotIndex, 1);
            dotIndex = s1.find('.');
        }
        // replace(s1.begin(), s1.begin()+index, '.', '');
        // s1.erase(std::find(s1.begin(), s1.end(), '\0'), std::find(s1.begin(), s1.end(), '\0')+1);
        int plusIndex = s1.find('+');
        if(plusIndex!=-1)
        s1.erase(plusIndex, index-plusIndex);
        str.insert(s1);
    }
    // for(auto x : newstrs){
    //     cout << x << endl;
        
    //     // str.insert(x);
    // }
   
    cout << str.size() << endl;
}