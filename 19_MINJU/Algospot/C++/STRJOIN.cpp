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
    vector<int> answer;
    for(int t=0;t<T;t++){
        int n;
        cin >> n;
        vector<int> vec(n,0);
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i=0;i<n;i++) cin >> vec[i];
        for(int i=0;i<n;i++) heap.push(vec[i]);
        int ans = 0;
        while(heap.size() > 1){
            int t1 = heap.top();
            heap.pop();
            int t2 = heap.top();
            heap.pop();
            heap.push(t1+t2);
            ans += (t1+t2);
        }
        // ans += heap.top();
        answer.push_back(ans);
    }
    for(int k : answer) cout << k << endl;
}