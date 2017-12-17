#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int trap(const vector<int>& vec){
    int maxVol = 0;
    int left = 0;
    int middle,right;
    int len = vec.size();
    int sub_vol;
    while(left < len){
        while(left + 1 < len && vec[left] <= vec[left+1])left++;
        sub_vol = 0;
        middle = left + 1;
        while(middle + 1 < len && vec[middle] >= vec[middle+1]){
            sub_vol += vec[middle];
            middle++;
        }
        sub_vol += vec[middle];
        right = middle + 1;
        while(right + 1 < len && vec[right] <= vec[right+1]){
            sub_vol += vec[right];
            right++;
        }
        sub_vol = (right - left - 1)*(min(vec[left],vec[right])) - sub_vol;
        if(sub_vol < 0)
            break;
        maxVol += sub_vol;
        left = right;
    }
    return maxVol;
}

int main(int argc, char* argv[]){
    vector<int> vec;
    int val;
    for(int i = 0; i < argc; i++){
        val = atoi(argv[i]);
        vec.push_back(val);
    }
    cout << trap(vec) <<endl;
    return 0;
}
