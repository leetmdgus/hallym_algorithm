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

long long answer = 0;

long long dfs(long long idx, vector<long long>& vec, long long N, vector<long long>& check, long long M){
    if(idx == N){
        long long hap = 0;
        long long mul = 1;
        for(long long i=0;i<N;i++) {
            if(check[i] == 0){
                 hap += 1;
                 mul *= vec[i];
            }
        }
        if(mul == 1) return 30;
        if(hap % 2 == 1) answer += M/mul;
        else answer -= M/mul;
        return 30;
    }
    check[idx] = 1;
    dfs(idx+1, vec, N, check, M);
    check[idx] = 0;
    dfs(idx+1, vec, N, check, M);
    return 30;
}

int main(){
    long long N;
    long long M;
    cin >> N >> M;
    vector<long long> vec;
    vector<long long> check(N, 0);
    for(long long i=0;i<N;i++){
        long long tempt;
        cin >> tempt;
        vec.push_back(tempt);
    }
    dfs(0, vec, N, check, M);
    cout << answer << endl;
}