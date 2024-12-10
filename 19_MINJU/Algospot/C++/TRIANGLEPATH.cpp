#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> answer;
    for(int z=0;z<T;z++){
        int n;
        cin >> n;
        vector<vector<int>> vec(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin >> vec[i][j];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if (j == 0) vec[i][j] += vec[i-1][j];
                else if(j == i) vec[i][j] += vec[i-1][j-1];
                else vec[i][j] += max(vec[i-1][j-1], vec[i-1][j]);
            }
        }
        int max_ = 0;
        for(int i=0;i<n;i++) max_ = max(max_, vec[n-1][i]);
        answer.push_back(max_);
    }
    for(int x : answer) cout << x << endl;
}