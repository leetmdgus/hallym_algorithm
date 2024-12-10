#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstdint>
#include <iomanip>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int N,K,M;
        cin >> N >> K >> M;
        vector<int> songs(N,0);
        vector<int> Likes(M,0);
        vector<vector<double>> vec(N, vector<double>(N,0));
        vector<double> answer(N,0);
        for(int i=0;i<N;i++) cin >> songs[i];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> vec[i][j];
            }
        }
        for(int i=0;i<M;i++) cin >> Likes[i];
        vector<vector<double>> dp(5, vector<double>(N,0));
        dp[0][0] = 1;
        for(int i=0;i<K;i++){
            for(int j=0;j<N;j++){
                double tempt = dp[i%5][j];
                for(int k=0;k<N;k++){
                    if(i+songs[j] <= K) dp[(i+songs[j])%5][k] += tempt*vec[j][k];
                }
            }
            for(int j=0;j<N;j++) if(i < K-3) dp[i%5][j] = 0;
        }
    for(int i=0;i<5;i++){
        for(int k=0;k<N;k++){
            if(i == K%5) answer[k] += dp[i][k];
            else if(i < K%5 && i+songs[k] > K%5) answer[k] += dp[i][k];
            else if(i > K%5 &&(i+songs[k])>4 &&(i+songs[k])%5 > K%5) answer[k] += dp[i][k];  
            }
        }
    for(int i=0;i<M;i++){
        cout << fixed << setprecision(8) << answer[Likes[i]] << " ";
    }
    cout << endl;
    }
}