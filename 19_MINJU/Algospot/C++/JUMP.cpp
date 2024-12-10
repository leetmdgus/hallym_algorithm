#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
int jump(int x,int y, vector<vector<int>>& matrix, vector<vector<int>>& check,int n){
    if (x >= n || y >= n) return 0;
    else if (x == n-1 && y == n-1) return 1;
    if(check[x][y] != -1) return check[x][y];
    check[x][y] = ((jump(x + matrix[x][y], y, matrix, check, n)) || (jump(x, y + matrix[x][y], matrix, check, n)));
    return check[x][y];
}
int main(){
    int T;
    cin >> T;
    vector<string> answer(T);
    array<int, 2> ck = {1,0};
    array<int, 2> cj = {0,1};
    for(int j=0;j<T;j++){
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<vector<int>> check(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> matrix[i][j];
            }
        }
        // cout << jump(0,0,matrix, check, n) <<"asdasddas "<< endl;
        if(jump(0,0,matrix, check, n) == 1) answer[j] = "YES";
        else answer[j] = "NO";
        // queue<tuple<int, int>> q;
        // q.push(make_tuple(0,0));
        // while(!q.empty()){
        //     auto tempt = q.front();
        //     q.pop();
        //     int x,y;
        //     tie(x,y) = tempt;
        //     for(int i=0;i<2;i++){
        //         int nx = x + ck[i]*matrix[x][y];
        //         int ny = y + cj[i]*matrix[x][y];
        //         if(nx >= 0 && nx < n && ny >= 0 && ny < n && check[nx][ny] == 0){
        //             check[nx][ny] = 1;
        //             q.push(make_tuple(nx,ny));
        //         }
        //     }

        // }
        // for(int i=0;i<n;i++){
        //         for(int k=0;k<n;k++){
        //             cout << check[i][k];
        //         }
        //         cout << endl;
        //     }
        // if(check[n-1][n-1] == 1){
        //     answer[j] = "YES";
        // }
        // else{
        //     answer[j] = "NO";
        // }
    }
    for(string x : answer) cout << x << endl;
    // cout << (-1||-1) << endl;
}