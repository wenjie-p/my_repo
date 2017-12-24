#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int searchInsert(const vector<int>& vec,const int val){
    int i=0,j=vec.size();
    int k;
    while(i < j){
        k = (i+j)/2;
        if(val == vec[k])
            return k;
        else if(val > vec[k]){
            if( k + 1 < vec.size()){
                if(vec[k+1] >= val)
                    return k+1;
            }else{
                return vec.size();
            }
            i = k + 1;
        }else{
            if( k - 1 >= 0){
                if(vec[k-1] < val)
                    return k;
                else if(vec[k-1] == val)
                    return k-1;
            }else{
                return 0;
            }
            j = k;
        }
    }
    //return 0;
}

int main(int argc, char* argv[]){
    vector<int> vec;
    int val;
    for(int i = 1; i < argc; i++){
        val = atoi(argv[i]);
        vec.push_back(val);
    }
    cin >> val;
    cout << searchInsert(vec,val) <<endl;
    return 0;
}
