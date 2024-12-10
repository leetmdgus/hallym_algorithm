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
    vector<double> ans;
    while(T-- > 0){
        int N,K;
        cin >> N >> K;
        vector<int> r;
        vector<int> c;
        for(int i=0;i<N;i++){
            int ri, ci;
            cin >> ri >> ci;
            r.push_back(ri);
            c.push_back(ci);
        }
        vector<double> grade;
        double start = 0.0;
        double end = 1.0;
        double answer = 100;
        for(int l=0;l<120;l++){
            double mid = (start + end)/2;
            priority_queue<double> pq;
            for(int i=0;i<N;i++){
                pq.push(mid*c[i]-r[i]);
            }
            double check = 0;
            for(int i=0;i<K;i++){
                check += pq.top();
                pq.pop();
            }
            if(check >= 0){
                end = mid;
                answer = min(answer, mid);
            }
            else start = mid;
            
        }
        ans.push_back(answer);
    }
    for(double a : ans) cout << fixed << setprecision(10)  << a << endl;
}