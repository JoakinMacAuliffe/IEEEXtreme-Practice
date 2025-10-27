    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;
    using ld = long double;

    // sieve of eratosthenes to compute primes
    vector<int> sieve(int n) {
        
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        vector<int> res;
        for (int p = 2; p <= n; p++){
            if (prime[p]){ 
                res.push_back(p);
            }
        }
        return res;
    }

    int main()
    {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> primes = sieve(1000001);
        unordered_map<int, vector<int>> semiprime_map;

        for(int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            if((ll)p * 2 > 1000000) break;
            
            for(int j = 0; j < primes.size(); j++) {
                ll product = (ll)p * primes[j];
                if(product > 1000000) break;
                semiprime_map[p].push_back(product);
            }
        }

        ll t;
        scanf("%lld", &t);

        while(t--) {
            ll L, R;
            scanf("%lld %lld", &L, &R);

            ll res = 0;

            for(int p : primes) {
                if(p * 2 > R) break;

                auto& cakes = semiprime_map[p];

                auto left = lower_bound(cakes.begin(), cakes.end(), L);
                auto right = upper_bound(cakes.begin(), cakes.end(), R);

                ll count = right - left;
                res += count * (count - 1) / 2;

            }
            printf("%lld\n", res);
        }

        return 0;
    }