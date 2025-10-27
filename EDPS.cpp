#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    if (N == 0) {
        cout << "Yes\n\n";
        return 0;
    }
    
    vector<int> dist(N);
    for (int i = 0; i < N; i++) {
        cin >> dist[i];
        if (dist[i] < 0 || dist[i] >= 2 * N) {
            cout << "No\n";
            return 0;
        }
    }
    
    sort(dist.begin(), dist.end());
    
    const int len = 2 * N;
    string s(len, ' ');
    multiset<int> foundDist;
    
    function<bool(int, vector<int>&)> solve = [&](int pos, vector<int>& openStack) -> bool {
        if (pos == len) {
            if (!openStack.empty()) return false;
            vector<int> found(foundDist.begin(), foundDist.end());
            return found == dist;
        }
        
        int balance = openStack.size();
        int remaining = len - pos;
        if (balance > remaining || ((remaining - balance) & 1)) return false;
        
        if (!openStack.empty()) {
            int openPos = openStack.back();
            openStack.pop_back();
            
            int d = pos - openPos - 1;
            foundDist.insert(d);
            
            bool valid = true;
            if (foundDist.size() > (size_t)N) {
                valid = false;
            } else {
                auto it1 = foundDist.begin();
                auto it2 = dist.begin();
                for (size_t i = 0; i < foundDist.size(); i++, ++it1, ++it2) {
                    if (*it1 != *it2) {
                        valid = false;
                        break;
                    }
                }
            }
            
            s[pos] = ')';
            if (valid && solve(pos + 1, openStack)) return true;
            s[pos] = ' ';
            
            foundDist.erase(foundDist.find(d));
            openStack.push_back(openPos);
        }
        
        openStack.push_back(pos);
        s[pos] = '(';
        if (solve(pos + 1, openStack)) return true;
        s[pos] = ' ';
        openStack.pop_back();
        
        return false;
    };
    
    vector<int> openStack;
    openStack.reserve(N);
    
    if (solve(0, openStack)) {
        cout << "Yes\n" << s << "\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}