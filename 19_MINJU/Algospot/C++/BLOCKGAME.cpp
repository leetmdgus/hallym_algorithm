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

int mapping_array(vector<vector<int>>& vec, int mode){
    int count = 1;
    int rtr = 0;
    if(mode == 0){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                rtr += count*vec[i][j];
                count *= 2;
            }
        }
    }
    else if(mode == 1){
        for(int i=0;i<5;i++){
            for(int j=4;j>=0;j--){
                rtr += count*vec[i][j];
                count *= 2;
            }
        }
    }
    else if(mode == 2){
        for(int i=4;i>=0;i--){
            for(int j=0;j<5;j++){
                rtr += count*vec[i][j];
                count *= 2;
            }
        }
    }
    else if(mode == 3){
        for(int i=4;i>=0;i--){
            for(int j=4;j>=0;j--){
                rtr += count*vec[i][j];
                count *= 2;
            }
        }
    }
    else if(mode == 4){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                rtr += count*vec[j][i];
                count *= 2;
            }
        }
    }
    else if(mode == 5){
        for(int i=0;i<5;i++){
            for(int j=4;j>=0;j--){
                rtr += count*vec[j][i];
                count *= 2;
            }
        }
    }
    else if(mode == 6){
        for(int i=4;i>=0;i--){
            for(int j=0;j<5;j++){
                rtr += count*vec[j][i];
                count *= 2;
            }
        }
    }
    else if(mode == 7){
        for(int i=4;i>=0;i--){
            for(int j=4;j>=0;j--){
                rtr += count*vec[j][i];
                count *= 2;
            }
        }
    }

    return rtr;
}

int BLOCK(vector<vector<int>>& vec, vector<int8_t>& dp, int mod, vector<vector<int>>& ck, vector<vector<int>>& cj){
    if (mod < 2) return -1*-1;
    int key = mapping_array(vec, 0);
    if(dp[key] != -2) return -dp[key];
    int rtr = -1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(vec[i][j] == 0 && rtr != 1){
                for(int k=0;k<ck.size();k++){
                    bool flag = true;
                    for(int l=0;l<ck[k].size();l++){
                        int nx = i + ck[k][l];
                        int ny = j + cj[k][l];
                        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && vec[nx][ny] == 0){
                            continue;
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        vec[i][j] = 1;
                        for(int l=0;l<ck[k].size();l++){
                            int nx = i + ck[k][l];
                            int ny = j + cj[k][l];
                            vec[nx][ny] = 1;
                        }

                        rtr = max(rtr, BLOCK(vec, dp, mod-ck[k].size()-1,ck,cj));
                        vec[i][j] = 0;
                        for(int l=0;l<ck[k].size();l++){
                            int nx = i + ck[k][l];
                            int ny = j + cj[k][l];
                            vec[nx][ny] = 0;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<8;i++){
        int tempt_key = mapping_array(vec, i);
        dp[tempt_key] = rtr;
    }
    return -rtr;

}

int main(){
    int T;
    cin >> T;
    vector<int8_t> dp(35000000,-2);
    vector<int> answer;
    vector<vector<int>> ck,cj;
    int cc[2][2] = {{1,2},{2,3}};
    for(int i=0;i<1;i++){
            vector<int> tempt;
            tempt.push_back(1);
            tempt.push_back(1);
            ck.push_back(tempt);

            tempt.clear();
            tempt.push_back(1);
            tempt.push_back(1);
            ck.push_back(tempt);
            
            tempt.clear();
            tempt.push_back(1);
            tempt.push_back(0);
            ck.push_back(tempt);

            tempt.clear();
            tempt.push_back(0);
            tempt.push_back(1);
            ck.push_back(tempt);

            tempt.clear();
            tempt.push_back(0);
            ck.push_back(tempt);

            tempt.clear();
            tempt.push_back(1);
            ck.push_back(tempt);

            tempt.clear();
            tempt.push_back(0);
            tempt.push_back(1);
            cj.push_back(tempt);

            tempt.clear();
            tempt.push_back(-1);
            tempt.push_back(0);
            cj.push_back(tempt);

            tempt.clear();
            tempt.push_back(1);
            tempt.push_back(1);
            cj.push_back(tempt);

            tempt.clear();
            tempt.push_back(1);
            tempt.push_back(0);
            cj.push_back(tempt);
            
            tempt.clear();
            tempt.push_back(1);
            cj.push_back(tempt);

            tempt.clear();
            tempt.push_back(0);
            cj.push_back(tempt);
        }
    for(int t=0;t<T;t++){
        vector<vector<int>> vec(5,vector<int>(5,0));
        int cnt = 25;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                char c;
                cin >> c;
                if(c == '#') {
                    vec[i][j] = 1;
                    --cnt;
                }
            }
        }
        int ans =  BLOCK(vec, dp, cnt, ck, cj);
        answer.push_back(ans);
    }
    for(int k : answer){
        if(k==-1) cout << "WINNING" << endl;
        else cout << "LOSING" << endl;
    }
}