#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string a, b;
    long long matchCost, mismatchCost, gapCost;

    cin >> n >> a >> m >> b >> matchCost >> mismatchCost >> gapCost;

    vector<vector<map<int, long long>>> dp(n + 1, vector<map<int, long long>>(m + 1));

    dp[0][0][0] = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(dp[i][j].empty()) continue;
            
            for(auto [gapLen, score] : dp[i][j]) {
                
                if(i < n && j < m) {
                    long long cost = (a[i] == b[j]) ? matchCost : mismatchCost;
                    long long newScore = score + cost;

                    if(gapLen > 0) {
                        newScore += (long long)gapLen * gapLen * gapCost;
                    }

                    if(!dp[i+1][j+1].count(0)) {
                        dp[i+1][j+1][0] = newScore;
                    } else {
                        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], newScore);
                    }
                }

                if(i < n) {
                    if(!dp[i+1][j].count(gapLen+1)) {
                        dp[i+1][j][gapLen+1] = score;
                    } else {
                        dp[i+1][j][gapLen+1] = max(dp[i+1][j][gapLen+1], score);
                    }
                }

                if(j < m) {
                    if(!dp[i][j+1].count(gapLen+1)) {
                        dp[i][j+1][gapLen+1] = score;
                    } else {
                        dp[i][j+1][gapLen+1] = max(dp[i][j+1][gapLen+1], score);
                    }
                }
            }
        }
    }

    long long res = LLONG_MIN;
    for(auto [gapLen, score] : dp[n][m]) {
        long long finalScore = score;
        if(gapLen > 0) {
            finalScore += (long long)gapLen * gapLen * gapCost;
        }
        res = max(res, finalScore);
    }

    cout << res << '\n';

    return 0;
}