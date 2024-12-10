#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int check(int index, vector<int>& x, int count){
    bool flag = true;
    for(int i = index; i < index+count;i++){
        if(x[i] == x[index]) continue;
        else flag = false; 
    }
    if(flag) return 1;
    flag = true;
    int tmp = x[index+1] - x[index];
    if(tmp == 1 || tmp == -1){
    for(int i = index; i < index+count;i++){
        if(x[i] == x[index] + (tmp*(i-index))) continue;
        else flag = false;
    }
    }
    else flag = false;
    if(flag) return 2;
    flag = true;
    for(int i = index; i < index+count;i++){
        if((i-index) % 2 == 0 && x[i] == x[index]) continue;
        else if((i-index) % 2 == 1 && x[i] == x[index+1]) continue;
        else flag = false;
    }
    if(flag) return 4;
    flag = true;
    int tempt = x[index+1] - x[index];
    for(int i = index; i < index+count;i++){
        int idx = i - index;
        if(x[index] + (idx*tempt) == x[i]) continue;
        else flag = false;
    }
    if(flag) return 5;
    else return 10;
}

int dp(int index, vector<int>& x, int length, vector<int>& ch){
    if(index == length) return 0;
    if(ch[index] != 0) return ch[index];
    int rtr = 1000000000;
    bool flag = true;
    int i;
    if(index + 2 < length) rtr = min(rtr, check(index, x, 3) + dp(index+3, x, length, ch));
    if(index + 3 < length) rtr = min(rtr, check(index, x, 4) + dp(index+4, x, length, ch));
    if(index + 4 < length) rtr = min(rtr, check(index, x, 5) + dp(index+5, x, length, ch));
    ch[index] = rtr;
    return rtr;
}

int main(){
    int T;
    cin >> T;
    vector<int> ans(T);
    for(int z=0;z<T;z++){
        string x;
        cin >> x;
        vector<int> vec;
        for(int i=0;i<x.length();i++) vec.push_back(x.at(i) - '0');
        vector<int> ch(vec.size(), 0);
        // for(int i=0;i<x.length();i++) cout << ch[i] << endl;
        int answer = dp(0, vec, vec.size(), ch);
        ans[z] = answer;
        // for(int i=0;i<x.length();i++) cout << ch[i] << " ";
    }
    for(int x : ans) cout << x << endl;
}