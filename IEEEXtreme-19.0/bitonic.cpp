#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M;
    cin >> M;
    
    // dp[n][last][increasing] where:
    // n = current sum
    // last = last value added
    // increasing = 0 (still increasing/at peak), 1 (now decreasing)
    
    vector<vector<array<long long, 2>>> dp(M + 1, vector<array<long long, 2>>(M + 1, {0, 0}));
    
    // Base case: sequences of length 1
    for (int v = 1; v <= M; v++) {
        dp[v][v][0] = 1;  // Single element, we're at the peak
    }
    
    // Fill DP table
    for (int sum = 1; sum < M; sum++) {
        for (int last = 1; last <= sum; last++) {
            // Still increasing (or at peak)
            if (dp[sum][last][0] > 0) {
                // Continue increasing: add value >= last
                for (int next = last; sum + next <= M; next++) {
                    dp[sum + next][next][0] = (dp[sum + next][next][0] + dp[sum][last][0]) % MOD;
                }
                // Start decreasing: add value < last
                for (int next = 1; next < last && sum + next <= M; next++) {
                    dp[sum + next][next][1] = (dp[sum + next][next][1] + dp[sum][last][0]) % MOD;
                }
            }
            
            // Currently decreasing
            if (dp[sum][last][1] > 0) {
                // Continue decreasing: add value <= last
                for (int next = 1; next <= last && sum + next <= M; next++) {
                    dp[sum + next][next][1] = (dp[sum + next][next][1] + dp[sum][last][1]) % MOD;
                }
            }
        }
    }
    
    // Output results
    for (int n = 1; n <= M; n++) {
        long long result = 0;
        for (int last = 1; last <= n; last++) {
            result = (result + dp[n][last][0] + dp[n][last][1]) % MOD;
        }
        cout << result;
        if (n < M) cout << " ";
    }
    cout << "\n";
    
    return 0;
}