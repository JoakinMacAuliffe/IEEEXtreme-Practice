#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int LOG = 20;

vector<pair<int,long long>> adj[MAXN];
int parent[MAXN][LOG];
long long dist_from_root[MAXN];
int depth[MAXN];
int A[MAXN];
int A_size = 0;

void dfs(int u, int p, long long d, int dep) {
    parent[u][0] = p;
    dist_from_root[u] = d;
    depth[u] = dep;
    
    for (auto [v, w] : adj[u]) {
        if (v != p) {
            dfs(v, u, d + w, dep + 1);
        }
    }
}

void preprocess_lca(int N) {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            } else {
                parent[i][j] = -1;
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
    
    if (u == v) return u;
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    
    return parent[u][0];
}

long long get_distance(int u, int v) {
    int l = lca(u, v);
    return dist_from_root[u] + dist_from_root[v] - 2 * dist_from_root[l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    // Preprocess: DFS from node 1 and build LCA
    dfs(1, -1, 0, 0);
    preprocess_lca(N);
    
    int M;
    cin >> M;
    
    long long last_ans = 0;
    
    while (M--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            long long x;
            cin >> x;
            x = ((x ^ abs(last_ans)) % N) + 1;
            A[A_size++] = x;
        }
        else if (type == 2) {
            if (A_size > 0) {
                A_size--;
            }
        }
        else {
            long long l, r, x;
            cin >> l >> r >> x;
            
            if (A_size == 0) continue;
            
            l = ((l ^ abs(last_ans)) % A_size) + 1;
            r = ((r ^ abs(last_ans)) % A_size) + 1;
            x = ((x ^ abs(last_ans)) % N) + 1;
            
            if (l > r) swap(l, r);
            
            long long max_dist = LLONG_MIN;
            for (int i = l - 1; i < r; i++) {
                max_dist = max(max_dist, get_distance(x, A[i]));
            }
            
            last_ans = max_dist;
            cout << last_ans << "\n";
        }
    }
    
    return 0;
}
