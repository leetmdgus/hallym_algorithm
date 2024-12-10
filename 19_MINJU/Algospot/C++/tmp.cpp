#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

using ull = unsigned long long;

ull Mapping_array(vector<int>& check) {
    ull result = 1;
    for (int i = 0; i < 10; i++) {
        ull rtr = 1;
        for (int j = 0; j < i; j++) {
            rtr *= 15;
        }
        result += (rtr*check[i]);
    }
    return result;
}


ull ZIMBABWE(vector<int>& check, unordered_map<ull, vector<int>>& dp, int m, ull count) {
    if (count == 0) return 0;

    ull any = Mapping_array(check);
    if (dp.find(any) != dp.end()) {
        return any;
    }

    dp[any] = vector<int>(m, 0);
    ull cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (check[i] > 0) {
            check[i]--;
            cnt = i * count;
            ull tempt = cnt % m;
            count /= 10;

            ull val = ZIMBABWE(check, dp, m, count);

            if (val == 0) {
                dp[any][tempt] = 1;
            } else {
                for (int j = 0; j < m; j++) {
                    dp[any][(j + tempt) % m] = (dp[any][(j + tempt) % m] + dp[val][j]) % 1000000007;
                }
            }
            count *= 10;
            check[i]++;
        }
    }
    return any;
}

ull find(int idx, vector<int>& lst, vector<int>& check, unordered_map<ull, vector<int>>& dp, int m, ull count, unordered_map<ull, vector<int>>& dp2) {
    if (idx == lst.size()) return 0;

    ull any = Mapping_array(check);
    dp2[any] = vector<int>(m, 0);
    for (int i = 0; i < 10; i++) {
        if (check[i] > 0 && i < lst[idx]) {
            check[i]--;
            ull cnt = i * count;
            count /= 10;
            ull val = ZIMBABWE(check, dp, m, count);

            count *= 10;
            check[i]++;
            ull tempt = cnt % m;
            if (val == 0) {
                dp2[any][tempt] = 1;
            } else {
                for (int j = 0; j < m; j++) {
                    dp2[any][(j + tempt) % m] = (dp2[any][(j + tempt) % m] + dp[val][j]) % 1000000007;
                }
            }
        } else if (check[i] > 0 && i == lst[idx]) {
            ull cnt = lst[idx] * count;
            count /= 10;
            check[i]--;

            ull val = find(idx + 1, lst, check, dp, m, count, dp2);

            count *= 10;
            ull tempt = cnt % m;
            check[i]++;
            if (val == 0) continue;

            for (int j = 0; j < m; j++) {
                dp2[any][(j + tempt) % m] = (dp2[any][(j + tempt) % m] + dp2[val][j]) % 1000000007;
            }
        }
    }
    return any;
}

int main() {
    int T;
    cin >> T;
    vector<int> answer;

    for (int t = 0; t < T; t++) {
        ull e;
        int m;
        cin >> e >> m;

        ull tmp = e;
        vector<int> lst;
        while (e > 0) {
            lst.push_back(e % 10);
            e /= 10;
        }
        reverse(lst.begin(), lst.end());

        vector<int> check(10, 0);
        unordered_map<ull, vector<int>> dp;
        unordered_map<ull, vector<int>> dp2;
        dp[0] = vector<int>(m, 0);

        for (int i : lst) {
            check[i]++;
        }
        // for(int k : lst) cout << k << " ";
        // cout << endl;
        ull rtr = find(0, lst, check, dp, m, pow(10, lst.size() - 1), dp2);
        answer.push_back(dp2[rtr][0]);
    }

    for (int k : answer) {
        cout << k << endl;
    }

    return 0;
}
