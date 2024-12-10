#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int LIS(vector<int>& vec){
    
}

int main(){
    int T;
    cin >> T;
    vector<int> answer(T);
    for(int z=0;z<T;z++){
        int n;
        cin >> n;
        vector<int> vec(n);
        vector<int> check(n, 0);
        for(int i=0;i<n;i++) cin >> vec[i];
        check[0] = 1;
        int ans = 1;
        for(int i=1;i<n;i++){
            int max_ = 0;
            for(int j=i-1;j>=0;j--){
                if(vec[i] > vec[j]) max_ = max(max_, check[j]);
            } 
            check[i] = max_ + 1;
            ans = max(ans, check[i]);
        }
        answer[z] = ans;
    }
    for(int k : answer) cout << k << endl;
}