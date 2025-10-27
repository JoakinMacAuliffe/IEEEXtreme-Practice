#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll find_k(ll N)
{
    if (N == 0)
        return 1;

    ll k = N - 1;

    k |= k >> 1;
    k |= k >> 2;
    k |= k >> 4;
    k |= k >> 8;
    k |= k >> 16;
    if (sizeof(N) > 4)
    {
        k |= k >> 32; // Include for long long (64-bit)
    }

    k += 1;

    return k;
}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin>>n;

        if(n%4 == 2) {
            printf("-1\n");
        } else if(n%2 == 1) {
            ll a = (n+1)/2;
            ll b = n;
            ll c = (n-1)/2+n;
        }   

    }
return 0;
}