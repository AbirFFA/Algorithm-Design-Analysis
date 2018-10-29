#include <bits/stdc++.h>

using namespace std;

int lis (int arr[], int n) {

    int lis[n], i, j, maxValue = 0;

    for (int i = 0; i < n; i++)
        lis[i] = 1;

    for (int i = 1; i < n; i++)
        for( int j = 0; j < i; j++)
            if( arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] =  lis[j] + 1;

    for (int i = 0; i < n; i++)
        if(maxValue < lis[i])
            maxValue = lis[i];
    return maxValue;

}

int main() {

    int arr[] = {10, 20, 9, 33, 21, 50, 41, 60};
    int n = 8;
    printf("%d", lis(arr, n));
    return 0;

}
