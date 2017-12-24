#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string multiply(string num1,string num2){
    int len1 = num1.length();
    int len2 = num2.length();
    int index;
    char str[len1+len2-1];
    memset(str,'0',len1+len2-1);
    for(int i = len2 - 1; i >=  0; i-- ){
        int com = 0;
        int val;
        int n = num2[i] - '0';
        for(int j = len1 - 1; j >= 0; j-- ){
            int m = num1[j] - '0';
            val = com + m*n;
            index = (len1 - j - 1)+(len2 - i - 1);
            val += str[index] - '0';
            com = val/10;
            str[index] = val%10 + '0';
        }
        if(com > 0){
            str[index-1] = com;
        }
    }
    string res(str);
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string num1,num2;
    cout<<"pls input two strings:"<<endl;
    cin>>num1>>num2;
    string str = multiply(num1,num2);
    cout<<"the result is: "<<str;
    return 0;
}
