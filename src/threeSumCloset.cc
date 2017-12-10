#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int threeSumCloset(vector<int>& input,int target){
    int len = input.size();
    if(len < 3) return 0;
    int closet = input[0] + input[1] + input[2];
    sort(input.begin(),input.end());
    for(int i = 0;i < len - 2; i++){
        if(i > 0 && input[i]==input[i-1])continue;
        int second = i + 1;
        int third = len - 1;
        while(second < third){
            int curSum = input[i] + input[second] + input[third];
            if(curSum == target) return curSum;
            if(abs(target - curSum) < abs(target - closet))
                closet = curSum;
            if(curSum > target)
                third--;
            else
                second++;
        }
    }
    return closet;
}
void Input(vector<int>& input,int& target){
    int i;
    cout<<"pls input the total number:"<<endl;
    cin>>i;
    int ele;
    while(i--){
        cin>>ele;
        input.push_back(ele);
    }
    cout<<"pls input the target:"<<endl;
    cin >> target;
}
int main(){
    vector<int> input;
    int target;
    Input(input,target);
    int ans = threeSumCloset(input,target);
    cout<<"target = "<<ans<<endl;
    return 0;
}
