#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

int main() {
    int t;
    ll a, b, p, x1, y1, x2, y2;

    scanf("%d", &t);

    while(t--) {

    scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &p, &x1, &y1, &x2, &y2);

    if(x1==x2&&mod(y1+y2,p)==0) {
        printf("POINT_AT_INFINITY\n");
        continue;
    }

    ll lambda;
    ll x3, y3;

    if(x1 != x2) {
        lambda = mod(mod(y2-y1, p) * mInverse(mod(x2-x1, p), p), p);
        x3 = mod((lambda*lambda-x1-x2),p);
        y3 = mod((lambda*(x1-x3)-y1),p);
        cout << x3 << " " << y3 << "\n";
        continue;
    } else if(x1 == x2) {
        if(y1==0) {
            cout << "POINT_AT_INFINITY" << "\n";
            continue;
        }else{
            lambda = mod(mod(3*x1*x1+a, p) * mInverse(mod(2*y1, p), p), p);            
            x3 = mod((lambda*lambda - 2*x1),p);
            y3 = mod((lambda*(x1-x3)-y1),p);
            cout << x3 << " " << y3 << "\n";
            continue;
        }
    }
}
return 0;
}