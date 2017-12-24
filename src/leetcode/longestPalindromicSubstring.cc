#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/*string longestPalindromicSubstring(const string& str){
    string reverse_str(str.rbegin(),str.rend());
    int j,k;
    int i = 0;
    int len = str.size();
    if(len == 1)
        return str;
    while(i < len){
        j = i;
        k = -1;
        while(k < len && str[j] != reverse_str[++k]);
        while(j < len && k < len && str[j++] == reverse_str[k++]);
        cout<<"i: "<<i<<"j: "<<j<<"k: "<<k<<endl;
        if(k >= len && str[j-1] != reverse_str[k-1]){
            j -= 2;
            k -= 2;
        }else{
            j--;
            k--;
        }
        if( j - i > 0 && (i + k == len - 1 ))
            break;
        i++;
    }
    return str.substr(i,(j - i + 1));
}
*/
int expandAroundCenter(const string& str,int i,int j){
    while(i >= 0 && j < str.size() && str[i] == str[j]){
        i--;
        j++;
    }
    return j - i - 1;
}
string lps(const string& str){
    int len;
    int maxLen = 0;
    int begin;
    for(int i =0;i < str.size(); i++){
        int left = expandAroundCenter(str,i,i);
        int right = expandAroundCenter(str,i,i+1);
        len = max(left,right);
        if(len > maxLen){
            maxLen = len;
            begin = i - (len-1)/2;
        }
    }

    return str.substr(begin,maxLen);
}
string Expand(const string& s){
    char* str = new char[2*s.size()+1];
    for(int i = 0; i < 2*s.size()+1; i++){
        if(i%2 == 0 ){
            str[i] = '#';
        }else{
            str[i] = s[i/2];
        }
    }
    string ss(str);
    return ss;
}
string Manacher(const string& str){
    string s = Expand(str);
    int* P = new int[s.size()];
    memset(P,0,s.size());
    int R,C;
    R = C = 0;
    int maxLen = -1;
    int pos;
    for(int i = 0; i < s.size(); i++){
        int i_mirror = 2*C - i;
        P[i] = (R > i) ? min((R-i),P[i_mirror]): 0;
        while(s[i - P[i] - 1] == s[i + 1 + P[i]]){
            P[i]++;
        }
        if(P[i] + i > R){
            R = P[i] + i;
            C = i;
        }
        if(P[i] > maxLen){
            maxLen = P[i];
            pos = i;
        }
    }
    pos = (pos - 1 - maxLen)/2;
    cout<<pos<<" "<<maxLen<<endl;
    return str.substr(pos,maxLen);
}
void Input(string& str){
    cout<<"pls input a string"<<endl;
    cin>>str;
}

void Output(const string& str){
    cout<<"the res is: "<<str<<endl;
}
int main(){
    string str;
    Input(str);
    //string res = lps(str);
    string res = Manacher(str);
    Output(res);
    return 0;
}
