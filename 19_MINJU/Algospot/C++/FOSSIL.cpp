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
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<pair<double, double>> fir;
        vector<pair<double, double>> sec;
        for(int i=0;i<n;i++){
            double x,y;
            cin >> x >> y;
            fir.push_back({x,y});
        }
        for(int i=0;i<m;i++){
            double x,y;
            cin >> x >> y;
            sec.push_back({x,y});
        }
        
    }
}