#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstdint>
#include <bitset>

using namespace std;

int INF = 100000000;

int dfs(long long check, int index, vector<long long>& ch, vector<long long>& acc, int count, int n){
    if(check == (1ULL<<n)-1) return count;
    int rtr = INF;
    if((check | acc[index]) != (1ULL<<n)-1) return INF;
    rtr = min(rtr, dfs((check | ch[index]), index+1, ch, acc, count+1,n));
    rtr = min(rtr, dfs(check, index+1, ch, acc, count,n));
    return rtr;
}

int main(){
    int T;
    cin >> T;
    // for(int i=0;i<53;i++){
    //     unsigned long long tempt = (1ULL<<i);
    //     cout << bitset<64>(tempt) << endl; 
    // }
    while(T > 0){
        T--;
        int n, m;
        cin >> n >> m;
        unordered_map<string, int> map;
        for(int i=0;i<n;i++){
            string tempt;
            cin >> tempt;
            map[tempt] = i;
        }
        vector<vector<int>> board(m, vector<int>(n,0));
        vector<int> count(m,0);
        for(int i=0;i<m;i++){
            int tempt;
            cin >> tempt;
            for(int j=0;j<tempt;j++){
                string t;
                cin >> t;
                board[i][map[t]] = 1;
            }
            count[i] = tempt;
        }
        vector<long long> ch(m, 0);
        for(int i=0;i<m;i++){
            int index = -1;
            int max_ = -1;
            for(int j=0;j<m;j++){
                if(count[j] > max_){
                    max_ = count[j];
                    index = j;
                }
            }
            count[index] = -2;
            long long check = 0;
            for(int j=0;j<n;j++){
                if(board[index][j] == 1) check = (check | (1ULL << j));
            }
            ch[i] = check;
        }
        // for(int i=0;i<ch.size();i++){
        //     std::cout << std::bitset<64>(ch[i]) << std::endl;
        // }
        // cout << endl;
        for(int i=0;i<ch.size();i++){
            int idx = i+1;
            while(idx < ch.size()){
                long long tmp = (ch[i] | ch[idx]);
                if(tmp == ch[i]) ch.erase(ch.begin()+idx);
                else idx++;
            }
        }
        vector<long long> acc(ch.size(),0);
        for(int i=0;i<ch.size();i++){
            long long tempt = 0;
             for(int j=i;j<ch.size();j++){
                tempt = tempt | ch[j];
             }
             acc[i] = tempt;
            //  cout << __builtin_popcount(acc[i]) << endl;
        }
        long long cnt = 0;
        cout << dfs(cnt, 0, ch, acc, 0, n) <<  endl;
    }
}