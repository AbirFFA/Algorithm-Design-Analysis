#include <bits/stdc++.h>

using namespace std;

int maximum (int a, int b) {
    //Get the maximum value
    if(a > b)
        return a;
    else
        return b;
}

//Calculating the value
int knapsack (int allowedweight, int value[], int weight[], int SIZE) {

    int i, w;
    int currentweight[SIZE + 1][allowedweight + 1];

    //Building table
    for(i = 0; i <= SIZE; i++) {

        for(w = 0; w <= allowedweight; w++) {

            if (i == 0 || w == 0)
                currentweight[i][w] = 0;

            else if (weight[i - 1] <= w)
                currentweight[i][w] =
                maximum(value[i - 1] + currentweight[i - 1][w - weight[i - 1]],
                        currentweight[i - 1][w]);

            else
                currentweight[i][w] = currentweight[i - 1][w];

        }
    }

    return currentweight[SIZE][allowedweight];
}

int main() {

    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int allowedweight = 50;

    int SIZE = sizeof(value) / sizeof(value[0]);

    printf("%d", knapsack(allowedweight, value, weight, SIZE));

    return 0;
}
///Output: 220