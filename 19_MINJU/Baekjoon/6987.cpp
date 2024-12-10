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
int victory[6];
int draw[6];
int defeat[6];
int main(){
    for(int t=0;t<4;t++){
        for(int i=0;i<6;i++){
            cin >> victory[i];
            cin >> draw[i];
            cin >> defeat[i];
        }
        int vic_hap = 0;
        int draw_hap = 0;
        int defeat_hap = 0;
        for(int i=0;i<6;i++) vic_hap += victory[i];
        for(int i=0;i<6;i++) draw_hap += draw[i];
        for(int i=0;i<6;i++) defeat_hap += defeat[i];

        if(vic_hap != defeat_hap  || draw_hap%2 != 0 || vic_hap+draw_hap+defeat_hap != 30) {
            cout << 0 << " ";
            break;
        }  

        for(int k=0;k<6;k++){
            for(int j=0;j<6;j++){
                if(k == j) continue;
                if(victory[k] > 0 && defeat[j] > 0) {
                    victory[k]--;
                    defeat[j]--;
                }
                else if(draw[k] > 0 && draw[j] > 0){
                    draw[k]--;
                    draw[j]--;
                }
                else if(defeat[k] > 0 && victory[j] > 0) {
                    defeat[k]--;
                    victory[j]--;
                }
            }
        }
        int count = 0;
        for(int i=0;i<6;i++) if(victory[i] > 0) count += 1;
        for(int i=0;i<6;i++) if(draw[i] > 0) count += 1;
        for(int i=0;i<6;i++) if(defeat[i] > 0) count += 1;
        // for(int i=0;i<6;i++) cout << victory[i] << " ";
        // cout << endl;
        // for(int i=0;i<6;i++) cout << draw[i] << " ";
        // cout << endl;
        // for(int i=0;i<6;i++) cout << defeat[i] << " ";
        // cout << endl;
        if(count > 0) cout << 0 << " ";
        else cout << 1 << " ";
    }

}