#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int Number_game(int n, vector<int>& vec, int l_idx, int r_idx, vector<vector<int>>& dp, int mod){
    if(mod == 0) return 0;
    else if(dp[l_idx][r_idx] != -100000000) return -dp[l_idx][r_idx]; 
    
    int& rtr = dp[l_idx][r_idx];
    if(mod >= 2){
        rtr = max(rtr, Number_game(n, vec, l_idx+2, r_idx, dp, mod-2));
        rtr = max(rtr, Number_game(n, vec, l_idx, r_idx-2, dp, mod-2));
    }
    rtr = max(rtr, vec[l_idx]+Number_game(n, vec, l_idx+1, r_idx, dp, mod-1));
    rtr = max(rtr, vec[r_idx]+Number_game(n, vec, l_idx, r_idx-1, dp, mod-1));
    // cout << l_idx << " " << r_idx << " " << dp[l_idx][r_idx] << endl;



    return -1*rtr;
}

int main(){
    int T;

    cin >> T;
    vector<int> answer;
    for(int t=0;t<T;++t){
        int n;
        cin >> n;
        vector<int> vec(n,0);
        for(int i=0;i<n;++i) cin >> vec[i];
        vector<vector<int>> dp(n, vector<int>(n, -100000000));
        answer.push_back(Number_game(n, vec, -0, n-1, dp, n));
        // for(int i=0;i<n;i++) cout << vec[i] << " ";
        // cout << endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    for(int k : answer) cout << -k << endl;
}