#include <bits/stdc++.h>

using namespace std;

int d, x, y;

void extendedEuclid (int A, int B) {
    if (A == 0) {
        d = B;
        x = 0;
        y = 1;
    } else {
        extendedEuclid (B%A, A);
        int temp = y;
        y = x;
        x = temp - (B/A)*x;
    }
}

int modInverse (int A, int M) {
    extendedEuclid (A, M);
    return (x%M+M)%M;
}

int findMinX (int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    int result = 0;

    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;

}

int main()
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};

    int k = sizeof(num)/sizeof(num[0]);

    cout << "X is " << findMinX(num,rem, k);
    return 0;
}
