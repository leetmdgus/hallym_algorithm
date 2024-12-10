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
        int N;
        cin >> N;
        vector<int> Russian(N,0);
        vector<int> Korean(N,0);
        for(int i=0;i<N;i++) cin >> Russian[i];
        for(int i=0;i<N;i++) cin >> Korean[i];
        vector<int> check(N,0);
        sort(Russian.begin(), Russian.end());
        int idx;
        idx = N-1;
        int ans = 0;
        while(idx >= 0){
            int gap_min = 10000000;
            int index = -1;
            int Korean_min = 1000000;
            int korea_index = -1;
            for(int i=0;i<N;i++){
                if(check[i] == 0 && Korean[i] >= Russian[idx]){
                    if(Korean[i]-Russian[idx] < gap_min){
                        gap_min = Korean[i]-Russian[idx];
                        index = i;
                    }
                }
                else if(check[i] == 0 && Korean[i] < Korean_min){
                    korea_index = i;
                    Korean_min = Korean[i];
                }
            }
            if(index != -1){
                check[index] = 1;
                ans++;
            }
            else{
                check[korea_index] = 1;
            }
            idx--;
        }
        answer.push_back(ans);
    }
    for(int k : answer) cout << k << endl;
}