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
    long long T;
    cin >> T;
    vector<long long> ans;
    while(T-- > 0){
        long long N, M;
        cin >> N >> M;
        long long answer = 2147483647;
        long long start = 1;
        long long end = 2000000000;
        long long standard = int(((long double)M/(long double)N)*100);
        for(long long i=0;i<300;i++){
            long long mid = (start + end) / 2;
            long long tempt_N = N+mid;
            long long tempt_M = M+mid;
            long long tempt_stardard = int(((long double)tempt_M/(long double)tempt_N)*100);
            if(tempt_stardard >= standard+1){
                answer = min(answer, mid);
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(answer == 2147483647) ans.push_back(-1);
        else ans.push_back(answer);
    }
    for(long long a : ans) cout << a << "\n";
}