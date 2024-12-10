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
    int N;
    cin >> N;
    vector<double> vec;
    vec.push_back(0);
    for(int i=0;i<N;i++){
        double tempt;
        cin >> tempt;
        vec.push_back(tempt);
    }
    int max_ = -1;
    for(int i=1;i<=N;i++){
        int count = 0;
        for(int k=1;k<=i-1;k++){
            bool ch = true;
            for(int j=k+1;j<=i-1;j++){
                double a,b;
                a = (vec[k]-vec[i])/((double)k-(double)i);
                b = vec[k] - (a*k);
                if(vec[j] >= a*j+b){
                    ch = false;
                    break;
                }
        }
            if(ch) count++;
            // cout << i << " " << ch << " " << k << endl;
        }
        for(int k=N;k>=i+1;k--){
            bool ch = true;
            for(int j=k-1;j>=i+1;j--){
                double a,b;
                a = (vec[k]-vec[i])/((double)k-(double)i);
                b = vec[k] - (a*k);
                if(vec[j] >= a*j+b){
                    ch = false;
                    break;
                }               
            }
            if(ch) count++;
            // cout << i << " " << ch << " " << k << endl;
        }
        max_ = max(max_, count);
    }
    cout << max_ << endl;
}