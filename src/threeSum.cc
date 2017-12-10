#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector< vector<int> > threeSum(vector<int>& input){
    vector< vector<int> > ans;
    int target;
    int len = input.size();
    sort(input.begin(),input.end());
    for(int i = 0;i < len; i++){
        if(i>0 && input[i]==input[i-1]) continue;
        int front = i + 1;
        int end = len - 1;
        target = -input[i];
        while(front < end){
            int num = input[front] + input[end];
            if(num < target)
                front++;
            else if(num > target)
                end--;
            else{
                vector<int> triplet(3,0);
                triplet[0] = input[front];
                triplet[1] = input[end];
                triplet[2] = -target;
                ans.push_back(triplet);
                //while(front < end && input[front]==triplet[0]) front++;
                //while(front < end && input[end]==triplet[1]) end--;
            }
        }
        //while(i + 1 < input.size()&&input[i+1] == -target) i++;
    }
    return ans;
}
void Input(vector<int>& input){
    int i;
    cout<<"pls input the total number:"<<endl;
    cin>>i;
    int ele;
    while(i--){
        cin>>ele;
        input.push_back(ele);
    }
}
void Output(const vector< vector<int> >& output){
    int len = output.size();
    for(int i = 0; i < len ;i++){
        cout<<"[";
        for(int j = 0; j < output[i].size(); j++){
            cout<<output[i][j]<<" ";
        }
        cout<<"]";
    }
}
int main(){
    vector<int> input;
    Input(input);
    vector< vector<int> > ans = threeSum(input);
    Output(ans);
    return 0;
}
