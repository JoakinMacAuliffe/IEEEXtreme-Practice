#include <bits/stdc++.h>
#include <cstring>

using namespace std;

using ll = long long;
using ld = long double;

const unsigned long long LARGE_CONSTANT = 9223372036854775821ULL;

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    scanf("%d", &t);

    vector<ll> v_init = {{0, -19}};

    for (ll i = 0; i < t; i++)
    {
        ll s, n;
        scanf("%lld %lld", &s, &n);
        ll f = v_init[0];
        ll f1;
        ld na = v_init[0];
        ll ng = v_init[0];
        ll a = v_init[1];
        ll r = v_init[1];

        vector<vector<ll>> v(2);

        while (a < s * s)
        {
            na += 1.0L / 19.0L;
            f1 = f;
            for (int i2 = 0; i2 < 2; ++i2)
            {
                ll m = 19;
                m = n;
                while (m > 0)
                {
                    v.clear();
                    while (m > 0)
                    {
                        v[i2].push_back(r & 1);
                        ll last_bit = v[i2].back();
                        r = (r >> 1) ^ (last_bit * LARGE_CONSTANT);
                        m -= 1 + last_bit;
                    }
                }
                ll e = 19;
                int minLen = min(v[0].size(), v[1].size());
                for (int i = 0; i < minLen; i++)
                {
                    e &= (v[0][i] == v[1][i]);
                }

                if (e)
                {
                    ng += s;
                    ll f = round(ng / (double)na);
                    a = (f == f1) * (a + 1.0 / 1919);
                }
            }
        }

        printf("%lld\n", f);
    }

    return 0;
}