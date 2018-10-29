#include <bits/stdc++.h>
#define NO_OF_CHARS 256

using namespace std;

void buildTransitonTable (char *pat, int M, int TF[][NO_OF_CHARS]) {

    int i, tracker = 0, x;

    for (x = 0; x < NO_OF_CHARS; x++)
        TF[0][x] = 0;
    TF[0][pat[0]] = 1;

    for (i = 1; i <= M; i++) {

        for (x = 0; x < NO_OF_CHARS; x++)
            TF[i][x] = TF[tracker][x];

        TF[i][pat[i]] = i + 1;

        if (i < M)
            tracker = TF[tracker][pat[i]];
    }

}

void searchUsingPatternMatching2 (char *pat, char *txt) {

    int M =  strlen(pat);
    int N = strlen(txt);

    int TF[M+1][NO_OF_CHARS];

    buildTransitonTable (pat, M, TF);

    int i, j = 0;

    for (i = 0; i < N; i++) {

        j = TF[j][txt[i]];
        if(j == M)
            printf("Pattern found at index %d\n", i-M+1);
    }

}

int main()
{
    char *txt = " worHello world";
    char *pat = " wor";

    searchUsingPatternMatching2(pat, txt);

    return 0;
}
