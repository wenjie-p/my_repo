// cartesian product 
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void output(const vector<string>& vec){
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
}

vector<string> cartesian_product(const string& digits){
    string digit2chars[10] = {"0", "1", "abc",
        "def", "ghi", "jkl", "mno", "opqrs", "tuv", "wxyz"
    };
    if(digits.empty())
        return vector<string>();
    vector<string> res;
    res.push_back("");
    for(int i = 0; i < digits.size(); i++){
        vector<string> temp;
        string chars = digit2chars[digits[i] - '0'];
        for(int j = 0; j < chars.size(); j++){
            for(int k = 0; k< res.size(); k++){
                temp.push_back(res[k] + chars[j]);
            }
        }
        res = temp;
    }
    return res;
}

int main(){
    string digits;
    cin >> digits;
    vector<string> vec = cartesian_product(digits);
    output(vec);
    return 0;
}
