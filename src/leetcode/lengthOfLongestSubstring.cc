#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int dp(const string& str){
    map<char,int> hash;
    int i=0,j=0,maxLen=0;
    while(j<str.length()){
        if(hash.find(str[j]) != hash.end()){
            i = max(i,hash[str[j]]);
        } 
        maxLen = max(maxLen,j-i+1);
        hash[str[j]] = j + 1; //we can skip all the elements in range [i,j] and let i be j+1
        j++;
    }
    return maxLen;
}

void Input(string& str){
    cout<<"pls input a string"<<endl;
    cin>>str;
}

void Output(const int& res){
    cout<<"the res is: "<<res<<endl;
}
int main(){
    string str;
    Input(str);
    int res = dp(str);
    Output(res);
    return 0;
}
