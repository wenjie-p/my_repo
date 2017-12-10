#include<iostream>
using namespace std;

int reverse(int i){
    int MAX = 0x80000000 - 1;
    int MIN = 0x80000000;
    int ii = i < 0? -i: i;
    int arr[10] = {-1};
    for(int j = 0; j < 10; j++){
        int m = ii % 10;
        int n = ii / 10;
        if(m == 0 && n == 0){
            break;
        }
        arr[j] = m;
        ii /= 10;
    }
    long long res = 0;
    bool removed = true;
    int j;
    for(j = 0; j < 10; j++){
        if(arr[j] == 0 && removed){
            continue;
        }
        if(arr[j] == 0){
            break;
        }
        removed = false;
        res = res*10 + arr[j];
    }
    if(res%10 != arr[j-1]){
        return 0;
    }
    //if(res > MAX || res < MIN)
        return 0;
    return i > 0? res : -res;
}



int main(){
    int i;
    cin >> i;
    int j = reverse(i);
    cout << j <<endl;
    return 0;
}
