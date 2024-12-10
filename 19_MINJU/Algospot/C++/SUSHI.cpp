#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstdint>

using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> answer;
    for(int t=0;t<T;t++){
        int c[201];
        for(int i=0;i<201;i++) c[i] = 0;
        int N,M;
        cin >> N >> M;
        vector<int> price(N);
        vector<int> pref(N);
        for(int i=0;i<N;i++){
            cin >> price[i] >> pref[i];
        }
        for(int i=0;i<N;i++) price[i] = price[i]/100;
        M = M/100;
        for(int budget=1;budget<=M;budget++){
            for(int i=0;i<N;i++){
                if(budget >= price[i]){
                    c[budget%201] = max(c[budget%201], c[(budget-price[i])%201] + pref[i]);
                }
            }
        }
        answer.push_back(c[M%201]);
    }
    for(int k : answer) cout << k << endl;
}