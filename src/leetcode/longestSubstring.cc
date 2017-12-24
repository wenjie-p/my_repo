#include<iostream>
#include<cstring>
using namespace std;
string LCS(const string& str1,const string& str2){
    int len1 = str1.size();
    int len2 = str2.size();
    int maxLen = -1;
    int begin;
    int** lcs = new int*[len1];
    for(int k=0;k<len1;k++){
        lcs[k] = new int[len2];
        memset(lcs[k],0,len2);
    }
    for(int i=0;i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(str1[i] == str2[j]){
                if(i==0 || j==0){
                    lcs[i][j] = 1;
                }else{
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }
                if(lcs[i][j] > maxLen){
                    maxLen = lcs[i][j];
                    begin = i - maxLen + 1;
                }
            }else{
                lcs[i][j] = 0;
            }
        }
    }
    return str1.substr(begin,maxLen);
}

void Output(const string& str){
    cout << "the res is: " << str << endl;
}
void Input(string& str1,string& str2){
    cout << "pls input two strings:" << endl;
    cin >> str1 >> str2;
}

int main(){
    string str1,str2;
    Input(str1,str2);
    string res = LCS(str1,str2);
    Output(res);
    return 0;
}

