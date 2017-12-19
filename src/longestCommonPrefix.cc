#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string longestCommonPrefix(const vector<string>& vec){
    int i,j;
    string prefix("");
    if(vec.size() == 0)
        return string("");
    for(i = 0; i < vec[0].size(); i++){
        for(j = 0; j < vec.size(); j++){
            if(i >= vec[j].size() || vec[0][i] != vec[j][i])
                return prefix;
        }
        prefix += vec[0][i];
    }
    return prefix;
}

int main(int argc, char* argv[]){
    vector<string> vec;
    for(int i = 1; i < argc; i++){
        vec.push_back(argv[i]);
    }
    cout << longestCommonPrefix(vec) <<endl;
    return 0;
}
