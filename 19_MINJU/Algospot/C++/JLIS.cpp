#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int JLis(int a,int b, vector<long long>& vec1, vector<long long>& vec2, int n, int m, int cache[101][101]){
    if (cache[a][b] != 0) return cache[a][b];
    // cout << a << "  " << b << endl;
    int ret = 2;
    
    long long max_element = max(vec1[a], vec2[b]);
    for(int i=a+1;i<n+1;i++){
        if (vec1[i] > max_element) ret = max(ret, JLis(i, b, vec1, vec2, n, m, cache) + 1);
    }
    for(int i=b+1;i<m+1;i++){
        if (vec2[i] > max_element) ret = max(ret, JLis(a, i, vec1, vec2, n, m, cache) + 1);
    }
    cache[a][b] = ret;
    return ret;
}

int main(){
    long long T;
    cin >> T;
    vector<long long> answer;
    for(long long z=0;z<T;z++){
        long long n,m;
        cin >> n >> m;
        // cout << n << " " << m << endl;
        int cache[101][101];
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                cache[i][j] = 0;
            }
        }
        vector<long long> f_vector(n+1);
        vector<long long> s_vector(m+1);
        f_vector[0] = LLONG_MIN;
        s_vector[0] = LLONG_MIN;
        for(long long i=1;i<n+1;i++) cin >> f_vector[i];
        for(long long j=1;j<m+1;j++) cin >> s_vector[j];
        answer.push_back(JLis(0,0, f_vector, s_vector, n, m, cache)-2);
        // for(int i=0;i<6;i++){
        //     for(int j=0;j<6;j++){
        //         cout << cache[i][j] << " " ;
        //     }
        //     cout << endl;
        // }
    }
    for(long long x : answer) cout << x << endl;
}