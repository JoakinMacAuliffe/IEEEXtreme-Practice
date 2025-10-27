#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    vector<string> original = grid;

    vector<pair<pair<int,int>, pair<int,int>>> restricciones;
    
    for(int i=0; i<n; i++) {
        // recorrer para buscar palabras horizontales
        int start = 0;

        while(start < m && grid[i][start] == '.') { // recorrer la fila completa
            start++;
        }

        if(start >= m) break;

        int end = start;
        while(end < m && grid[i][end] != '.') {
            end++;
        }

        int len = end-start;
        for(int j=0; j<len/2; j++) {
            int left = start + j;
            int right = end - 1 - j;
            restricciones.push_back({{i, start+j}, {i, end - 1 - j}});
        }

        start = end;

    }

    return 0;
}