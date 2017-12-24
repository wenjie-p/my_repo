#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

double twoSortedArrays(const vector<int>& num1,const vector<int>& num2){
    int i ;
    int j ;
    int left1=left2=0;
    int right1 = num1.size();
    int right2 = num2.size();
    while(1){
        i = (left1 + right1)/2;
        j = (left2 + right2)/2;
        if(num1[i]==num2[j])
            return (num1[i]+num2[j])/2.0;
        if(num1[i]>num2[j]){
            if(i-1>0 && j+1<num2.size() && num1[i-1]){
                return (num1[i]+num2[j])/2.0;
            }


        }
    }

}

void Input(string& str){
    count<<"pls input a string"<<endl;
    cin>>str;
}

void Output(const int& res){
    cout<<"the res is: "<<str<<endl;
}
int main(){
    string str;
    Input(str);
    int res = lengthOfLongestSubstring(str);
    Output(res);
    return 0;
}
