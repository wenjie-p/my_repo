#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<int> two_sum(vector<int>& nums,int target){
    int length = nums.size();
    vector<int> ans;
    map<int,int> mp;
    for(int i = 0;i < length; i++ ){
        if(mp.find(nums[i])!=mp.end()){
            ans.push_back(i);
            ans.push_back(mp[nums[i]]);
            break;
        }
        mp[target - nums[i]] = i;
    }
    return ans;
}
int main(){
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(3);
    //vec.push_back(3);
    int target = 6;
    vector<int> ans;
    ans = two_sum(vec,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
