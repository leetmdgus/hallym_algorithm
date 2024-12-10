#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <unordered_map>

using namespace std;

// Check 배열을 이용하여 현재 상태를 이진수로 매핑
int Map_array(const vector<int>& check) {
    int rtr = 0;
    for (int idx = 0; idx < check.size(); ++idx) {
        rtr += (1 << idx) * check[idx];
    }
    return rtr;
}

// 직접적인 동적 계획법 함수
double direct_dp(int idx, const vector<vector<double>>& lst, vector<unordered_map<int, double>>& dp, vector<int>& check) {
    int any = Map_array(check);
    if (any == 0) {
        return 0.0;
    } else {
        if (dp[idx].count(any)) {
            return dp[idx][any];
        }
        dp[idx][any] = numeric_limits<double>::max();
        for (int i = 0; i < check.size(); ++i) {
            if (check[i] == 0) {
                continue;
            }
            check[i] = 0;
            dp[idx][any] = min(dp[idx][any], lst[idx][i] + direct_dp(i, lst, dp, check));
            check[i] = 1;
        }
        return dp[idx][any];
    }
}

int main() {
    int T;
    cin >> T;
    vector<double> answer;
    
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<vector<double>> lst(N, vector<double>(N));
        vector<int> check(N, 1);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> lst[i][j];
            }
        }

        vector<unordered_map<int, double>> dp(N);

        double ans = numeric_limits<double>::max();
        for (int i = 0; i < N; ++i) {
            check[i] = 0;
            ans = min(ans, direct_dp(i, lst, dp, check));
            check[i] = 1;
        }
        answer.push_back(ans);
    }

    for (double k : answer) {
        printf("%.10f\n", k);
    }

    return 0;
}