#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define max 1000000
lli a[max];
lli diff(lli a, lli b, lli c);
lli maximum(lli size);
lli returnMax(lli a, lli b) {
    return a > b ? a : b;
}
int main()
{
    int test;
    cin >> test;
    int size;
    int element;
    while (test--) {

        cin >> size;

        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
        cout << maximum(size) << endl;

    }
}

lli maximum(lli size) {
    sort(a, a + size);
    lli s = returnMax(diff(a[0], a[1], a[size - 1]), diff(a[0], a[size - 2], a[size - 1]));
    return s;
}

lli diff(lli a, lli b, lli c) {

    return llabs(a - b) + llabs(b - c) + llabs(a - c);
}