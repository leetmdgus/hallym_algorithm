/*  Algorithm : 0-1 Knapsack
*   Tag : Dynamic Programming , Knapsack Problem
*   Problem : Baekjoon, No. 12865
*   URL : https://www.acmicpc.net/problem/12865
*/

#include <iostream>

using namespace std;

int N, K, dp[100005][105];

int main() {
    cin>> N >> K;
  
    for(int i = 1, W, V; i <= N; ++i) {
        cin >> W >> V;
        for(int j = 0; j <= K; ++j) {
            if(W <= j) {
                dp[j][i] = max(dp[j][i - 1], dp[j - W][i - 1] + V);
            }
            else {
                dp[j][i] = dp[j][i - 1];
            }
        }
    }
    
    cout << dp[K][N];
    
    return 0;
}