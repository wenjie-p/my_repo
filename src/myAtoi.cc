#include<iostream>
using namespace std;
const int INT_MAX = 0x7FFFFFFF;
const int INT_MIN = 0x80000000;
int myAtoi(string str){
    long long res = 0;
    int sign = 1;
    int digit;
    int i = 0;
    int val;
    while(str[i] == ' ')i++;
    if(str[i] == '+' || str[i] == '-')
        sign = str[i++] == '-'? -1:1;
    while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
        digit = str[i++] - '0';
        res = res*10 + digit;
        val = res * sign;
        if(val >= INT_MAX)
            return INT_MAX;
        else if(val <= INT_MIN)
            return INT_MIN;
    }
    res *= sign;
    return res;
}

int main(){
    string str;
    cin >> str;
    cout << myAtoi(str) <<endl;
    return 0;
}
