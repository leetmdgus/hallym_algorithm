#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<string> answer;
    for(int i=0;i<T;i++){
        int cnt;
        string str;
        cin >> str;
        cin >> cnt;
        vector<string> ans;
        vector<string> vec(cnt);
        for(int j=0;j<cnt;j++){
            cin >> vec[j]; 
        }
        for(int j=0;j<cnt;j++){
            int n = str.size()+1;
            int m = vec[j].size()+1;
            vector<vector<int>> ch(n, vector<int>(m, 0));
            ch[0][0] = 1;
            for(int k=1;k<n;k++){
                for(int l=1;l<m;l++){
                    if(str[k-1] == '*' && l == 1 && ch[k-1][l-1] == 1) ch[k][0] = 1;
                    if(str[k-1] != '?' && str[k-1] != '*'){
                        if (str[k-1] == vec[j][l-1]) ch[k][l] = (ch[k-1][l-1] == 1) ? 1 : 0; 
                    }
                    else if(str[k-1] == '?'){
                        ch[k][l] = (ch[k-1][l-1] == 1) ? 1 : 0; 
                    }
                    else if(str[k-1] == '*'){
                        ch[k][l] = (ch[k-1][l-1] == 1) ? 1 : 0; 
                        if(ch[k][l] == 0) ch[k][l] = (ch[k][l-1] == 1) ? 1 : 0;
                        if(ch[k][l] == 0) ch[k][l] = (ch[k-1][l] == 1) ? 1 : 0;
                    }
                }
            }
            if (ch[n-1][m-1] == 1) ans.push_back(vec[j]);
            // cout << str << "  " << vec[j] << endl;
            // for(int k=0;k<n;k++){
            //     for(int l=0;l<m;l++){
            //         cout << ch[k][l] << "  " ;
            //     }
            //     cout << endl;
            // }
        }
        sort(ans.begin(), ans.end());
        for(string x : ans) answer.push_back(x);
    }
    for(string a : answer) cout << a << endl;
}