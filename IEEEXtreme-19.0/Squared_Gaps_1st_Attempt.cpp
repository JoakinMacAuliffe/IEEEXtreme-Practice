#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, match, mismatch, gap;
    string a, b;

    cin >> n;
    cin >> a;

    cin >> m;
    cin >> b;

    cin >> match >> mismatch >> gap;

    if (n > m)
    {
        char frameA[n], frameB[n];
        int matches = 0, mismatches = 0, gaps = 0;
        for (int i = 0; i < n; i++)
        { // elegir palabra de mayor tamano
            frameA[i] = a[i];
            int indexB = 0;
            if (frameA[i] == b[indexB])
            { // match
                matches++;
                indexB++;
            }
            else if (frameA[i] != NULL && frameA[i] != b[indexB])
            {
                mismatches++;
            }
            else
            {
                gaps++;
            }
        }

        int result = match * matches + mismatch * mismatch + gap * gaps;
         printf("%d\n", result);

    }
    else
    {
        char frameB[m], frameA[m];
        int matches = 0, mismatches = 0, gaps = 0;
        for (int i = 0; i < m; i++)
        { // elegir palabra de mayor tamano
            frameB[i] = b[i];
            int indexA = 0;
            if (frameA[i] == a[indexA])
            { // match
                matches++;
                indexA++;
            }
            else if (frameA[i] != NULL && frameA[i] != a[indexA])
            {
                mismatches++;
            }
            else
            {
                gaps++;
            }
        }
        int result = match * matches + mismatch * mismatch  + gap * gaps;
        printf("%d\n", match*matches);
        printf("%d\n", result);
        printf("%d\n", gaps);
    }

    return 0;
}