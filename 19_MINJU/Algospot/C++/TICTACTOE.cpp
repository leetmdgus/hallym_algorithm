#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int mapping_array(vector<char>& vec){
    int rtr = 0;
    int exponent = 1;
    for(int i=0;i<3;i++){
        if(vec[i] == '.') rtr += exponent*0;
        else if(vec[i] == 'x') rtr += exponent*1;
        else if(vec[i] == 'o') rtr += exponent*2;
        else cout << ("Error") << '\n';
        exponent *= 3;
    }
    return rtr;
}

int check(vector<vector<char>> &vec){
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    for(int i=0;i<3;i++){
        if(vec[i][0] == 'x') ++count1;
        if(vec[i][1] == 'x') ++count2;
        if(vec[i][2] == 'x') ++count3;
    }
    if(count1 == 3 || count2 == 3 || count3 == 3) return 1;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    for(int i=0;i<3;i++){
        if(vec[0][i] == 'x') ++count1;
        if(vec[1][i] == 'x') ++count2;
        if(vec[2][i] == 'x') ++count3;
    }
    if(count1 == 3 || count2 == 3 || count3 == 3) return 1;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    for(int i=0;i<3;i++){
        if(vec[i][i] == 'x') ++count1;
        if(vec[i][2-i] == 'x') ++count2;
    }
    if(count1 == 3 || count2 == 3 || count3 == 3) return 1;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    for(int i=0;i<3;i++){
        if(vec[i][0] == 'o') ++count1;
        if(vec[i][1] == 'o') ++count2;
        if(vec[i][2] == 'o') ++count3;
    }
    if(count1 == 3 || count2 == 3 || count3 == 3) return 2;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    for(int i=0;i<3;i++){
        if(vec[0][i] == 'o') ++count1;
        if(vec[1][i] == 'o') ++count2;
        if(vec[2][i] == 'o') ++count3;
    }
    if(count1 == 3 || count2 == 3 || count3 == 3) return 2;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    for(int i=0;i<3;i++){
        if(vec[i][i] == 'o') ++count1;
        if(vec[i][2-i] == 'o') ++count2;
    }
    if(count1 == 3 || count2 == 3 || count3 == 3) return 2;
    return 0;
}

int direct_dfs(bool flag, vector<vector<char>>& vec, vector<vector<vector<int>>>& dp, int cnt){
    int check1 = mapping_array(vec[0]);
    int check2 = mapping_array(vec[1]);
    int check3 = mapping_array(vec[2]);
    if(dp[check1][check2][check3] != -1) return dp[check1][check2][check3];
    int rtr = 2;
    if(check(vec)) {
        if(flag) return 2;
        else return 1;
    }
    if(cnt == 9) return 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(vec[i][j] == '.'){
                if(flag){
                    vec[i][j] = 'x';
                    int tempt = direct_dfs(false, vec, dp, cnt+1);
                    vec[i][j] = '.';
                    if(tempt == 0) dp[check1][check2][check3] = 0;
                    else if(tempt == 1) return dp[check1][check2][check3] = 1;
                    else if(tempt == 2) continue;
                }
                else{
                    vec[i][j] = 'o';
                    int tempt = direct_dfs(true, vec, dp, cnt+1);
                    vec[i][j] = '.';
                    if(tempt == 0) dp[check1][check2][check3] = 0;
                    else if(tempt == 1) continue;
                    else if(tempt == 2) return dp[check1][check2][check3] = 2;
                }
            }
        }
    }
    if(dp[check1][check2][check3] == -1){
        if(flag) return dp[check1][check2][check3] = 2;
        else return dp[check1][check2][check3] = 1;
    }
    else return dp[check1][check2][check3];
}


int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        vector<vector<char>> vec(3, vector<char>(3,'.'));
        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(27,-1)));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin >> vec[i][j];
            }
        }
        int ans = check(vec);
        if(ans == 1 || ans == 2) {
            char c = (ans==1) ? 'x':'o'; 
            cout << c<< endl;

        }
        else{
            int count = 0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(vec[i][j] != '.') ++count;
                }
            }
            int tmp = 0;
            if(count%2==0) tmp = direct_dfs(true,vec,dp,count);
            else tmp = direct_dfs(false, vec, dp, count);
            if(tmp == 0) cout << "TIE" << endl;
            else if(tmp == 1) cout << 'x' << endl;
            else if(tmp == 2) cout << 'o' << endl;
            else cout << "Error" << endl;
        }
    }
}