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
    vector<int> ans;
    while(T-- > 0){
        int N, K;
        cin >> N >> K;
        vector<tuple<int, int, int>> vec;
        for(int i=0;i<N;i++){
            int L,M,G;
            cin >> L >> M >> G;
            vec.push_back(make_tuple(L,M,G));
        }
        int start = 0, end = 8030000;
        int answer = 2147483647;
        int cnt = 0;
        while(start <= end){
            int mid = (start + end) /2;
            int count = 0;
            // cnt++;
            // if(cnt ==/ 50) break;
            for(const auto& item : vec){
                int L = get<0>(item);
                int M = get<1>(item);
                int G = get<2>(item);
                if(mid > L) count = count + M/G + 1;
                else if(mid < L-M) continue;
                else if(L-M <= mid && mid <= L) count = count + (mid-(L-M))/G+ 1;
            }
            if(count < K) start = mid+1;
            else if(count >= K) {
                answer = min(answer, mid);
                end = mid-1;
            }
        }
        ans.push_back(answer);
    }
    for(int l : ans) cout << l << "\n";
}