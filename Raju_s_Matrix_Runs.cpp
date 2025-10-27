#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> matrix;
vector<vector<int>> dp;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    
    int maxLen = 1;  // Current cell counts as length 1
    
    // Try all 4 directions
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        // Check bounds and increasing condition
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && matrix[nx][ny] > matrix[x][y]) {
            maxLen = max(maxLen, 1 + dfs(nx, ny));
        }
    }
    
    return dp[x][y] = maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    matrix.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, -1));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int maxPath = 0;
    
    // Try starting from every cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maxPath = max(maxPath, dfs(i, j));
        }
    }
    
    cout << maxPath << "\n";
    
    return 0;
}
