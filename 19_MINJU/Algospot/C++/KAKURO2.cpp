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
#include <string.h>
using namespace std;

int getSize(int mask){
    int count = 0;
    for(int i=0;i<10;i++){
        int tempt = (mask & (1 << i));
        if(tempt != 0) ++count;
    }
    return count;
}
int getSum(int mask) {
    int hap=0;
    for(int i=1;i<10;i++){
        int tempt = (mask & (1 << i));
        if(tempt != 0) hap += i;
    }
    return hap;
}

int candidates[10][46][1024];

void generateCandidates(){
    memset(candidates, 0, sizeof(candidates));

    for(int set = 0; set < 1024; set += 2){
        int l = getSize(set), s = getSum(set);
        int subset = set;
        while(true){
            
            candidates[l][s][subset] |= (set & ~subset);
            if(subset == 0) break;
            subset = (subset-1) & set;
        }
    }
}



void put(int y, int x, int val, vector<int>& known, vector<vector<vector<int>>>& hint, vector<vector<int>>& value){
    for(int h=0;h<2;++h){
        known[hint[y][x][h]] += (1 << val);
    }
    value[y][x] = val;
}
void remove(int y, int x, int val, vector<int>& known, vector<vector<vector<int>>>& hint, vector<vector<int>>& value){
    for(int h=0;h<2;h++) known[hint[y][x][h]] -= (1 << val);
    value[y][x] = 0;
}
int getCandHint(int hint, vector<int>& sum, vector<int>& length, vector<int>& known){
    return candidates[length[hint]][sum[hint]][known[hint]];
}
int getCandCoord(int y, int x, vector<vector<vector<int>>>& hint, vector<int>& sum, vector<int>& length, vector<int>& known){
    return (getCandHint(hint[y][x][0], sum, length, known) & getCandHint(hint[y][x][1], sum, length, known));
}
bool search(int n, vector<vector<int>>& color, vector<vector<int>>& value, vector<vector<vector<int>>>& hint, vector<int>& sum, vector<int>& length, vector<int>& known){
    int y = -1, x = -1, minCands = 1023;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(color[i][j] == 1 && value[i][j] == 0){
                int cands = getCandCoord(i, j, hint, sum, length, known);
                if(getSize(minCands) > getSize(cands)){
                    minCands = cands;
                    y = i; x = j;
                }
            }
        }
    }
    if(minCands == 0) return false;
    if(y == -1){
        return true;
    }
    for(int val = 1; val < 10; val++){
        if (minCands & (1 << val)){
        put(y, x, val, known, hint, value);
        if(search(n, color, value, hint, sum, length, known)) return true;
        remove(y, x, val, known, hint, value);
        }
    }
    return false;
}

int main(){
     int T;
     cin >> T;
     generateCandidates();
     while(T--){
        int n;
        cin >> n;
        vector<vector<int>> color(n, vector<int>(n, 0));
        vector<vector<int>> value(n, vector<int>(n, 0));
        vector<vector<vector<int>>> hint(n, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<int> sum(n*n, 0);
        vector<int> length(n*n, 0);
        vector<int> known(n*n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> color[i][j];
            }
        }
        int q;
        cin >> q;

        for(int i=0;i<q;i++){
            int y,x,h,s;
            cin >> y >> x >> h >> s;
            y--;
            x--;
            sum[i] = s;
            int cnt = 0;
            if(h == 0){
                x++;
                while(x < n && color[y][x] == 1){
                    hint[y][x][h] = i;
                    ++cnt;
                    ++x;
                }
            }
            else{
                y++;
                while(y < n && color[y][x] == 1){
                    hint[y][x][h] = i;
                    ++cnt;
                    ++y;
                }
            }
            length[i] = cnt;
        }
        if(search(n, color, value, hint, sum, length, known)){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << value[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else{
            cout << "ASDADS";
        }
     }

}