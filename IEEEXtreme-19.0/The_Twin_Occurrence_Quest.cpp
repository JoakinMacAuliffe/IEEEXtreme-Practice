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

    scanf("$d", &t);

    int arr[t];

    for (int i = 0; i < t; ++i)
    {
        scanf("$d", &arr[i]); 
    }

    int n = 2 * arr[2];
    int k = find_k(n);

    // (A + B + C) - (A ^ B ^ C) = N

    if ()

        return 0;
}