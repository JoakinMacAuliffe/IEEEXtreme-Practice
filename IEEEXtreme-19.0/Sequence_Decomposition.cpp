#include <bits/stdc++.h>
using namespace std;

// Pattern positions (0..5): '1','1','2','0','1','2'
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string s;
        cin >> s;
        const int n = (int)s.size();

        vector<array<int,6>> seqs;
        seqs.reserve(n / 6 + 8);

        // wait[pos] holds IDs of sequences that have filled positions [0..pos-1]
        // and currently need pattern[pos]
        deque<int> wait[6];

        vector<int> done;
        done.reserve(n / 6 + 8);

        auto start_seq = [&](int idx) {
            int id = (int)seqs.size();
            seqs.push_back({});
            seqs[id][0] = idx;       // first '1'
            wait[1].push_back(id);   // now needs second '1'
        };

        auto adv = [&](int pos, int idx) {
            int id = wait[pos].front();
            wait[pos].pop_front();
            seqs[id][pos] = idx;
            if (pos == 5) {
                done.push_back(id);         // completed "112012"
            } else {
                wait[pos + 1].push_back(id);
            }
        };

        // Greedy with priorities that guarantee feasibility:
        // '1' -> wait[4] > wait[1] > start
        // '2' -> wait[2] > wait[5]  (build 1120 pipelines before completing 11201)
        // '0' -> wait[3] (must exist for valid strings)
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int idx = i + 1;

            if (c == '1') {
                if (!wait[4].empty()) {
                    adv(4, idx);
                } else if (!wait[1].empty()) {
                    adv(1, idx);
                } else {
                    start_seq(idx);
                }
            } else if (c == '2') {
                if (!wait[2].empty()) {
                    adv(2, idx);
                } else {
                    // For valid inputs this must be available
                    adv(5, idx);
                }
            } else { // c == '0'
                // For valid inputs this must be available
                adv(3, idx);
            }
        }

        // Output exactly |s|/6 lines
        for (int id : done) {
            const auto &a = seqs[id];
            for (int j = 0; j < 6; ++j) {
                if (j) cout << ' ';
                cout << a[j];
            }
            cout << '\n';
        }
    }
    return 0;
}   