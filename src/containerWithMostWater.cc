#include<iostream>
#include<vector>
using namespace std;

void Output(int res){
    cout << res <<endl;
}

int sub_cal(int i,int j,int ii,int jj){
    int len = ii > jj? jj: ii;
    return (j-i)*len;
}

int Calculate(const vector<int> container){
    int maxVol = -1;
    int val;
    int left = 0;
    int right = container.size() - 1;
    while(left < right){
        val = sub_cal(left,right,container[left],container[right]);
        if(val > maxVol){
            maxVol = val;
        }
        if(container[left] < container[right]){
            left++;
        }else{
            right--;
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            val = sub_cal(i,j,container[i],container[j]);
            if(val > maxVol){
                maxVol = val;
                res.first = i;
                res.second = j;
            }
        }
    }*/
    return maxVol;
}

void Input(vector<int>& vec){
    int n;
    cin >> n;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        vec.push_back(val);
    }
}

int main(){
    /*
    int n; 
    cin >> n;
    container = new int[n];
    for(int i = 0; i < n; i++)
        cin >> container[i];*/
    vector<int> vec;
    Input(vec);
    int res = Calculate(vec);
    Output(res);
    return 0;
}
