#include<iostream>
using namespace std;
bool judge(int i){
    if(i < 0 || ((i % 10 == 0 && i != 0)))
        return false;
    int j = 0;
    while(i > j){
        j = j*10 + i%10;
        i /= 10;
    }
    return (i == j || i == j/10)? true:false;
}
int main(){
    int i;
    cin >> i;
    if(judge(i))
        cout << "true" <<endl;
    else
        cout << "false" <<endl;
    return 0;
}
