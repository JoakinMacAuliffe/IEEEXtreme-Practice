    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;
    using ld = long double;

    const ll MOD = 998244353;

    ll mInverse(ll n, ll p) {
    ll res=1, base=n, exp=p-2;
    while(exp>0) {
        if(exp & 1) res = (res * base) % p;
        base=(base*base)%p;
        exp >>= 1;
    }
    return res;
}

    ll mod(ll n, ll p) {
        return ((n%p) + p)%p;
    }

    int main()
    {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n, m;
        cin >> n >> m;
        int S[n];
        for(int i=0; i<n; i++) {
            cin >> S[i];
        }

        for(int i=0; i<m; i++){
            int type;
            cin >> type;

            if(type == 1) {
                ll X;
                cin >> X;
                for(int i=0; i<n; i++) {
                    S[i] = mod(S[i] + X, MOD);
                }
            } else {
                for(int i=0; i<n; i++) {
                    S[i] = mInverse(S[i], MOD);
                }
            }

            ll sum = 0;
            for(int i=0; i<n; i++) {
                sum = mod(sum + S[i], MOD);
            }

            cout << sum << "\n";
        }

        return 0;
    }