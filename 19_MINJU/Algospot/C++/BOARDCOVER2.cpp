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
    while (T > 0){
        T--;
        int H,W,R,C;
        cin >> H >> W >> R >> C;
        vector<vector<char>> board(H, vector<char>(W, '.'));
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin >> board[i][j];
            }
        }
        vector<vector<char>> c(R, vector<char>(C, '.'));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin >> c[i][j];
            }
        }
        vector<vector<vector<int>>> check(4, vector<vector<int>>(R, vector<int>(C, 0)));

    }

}