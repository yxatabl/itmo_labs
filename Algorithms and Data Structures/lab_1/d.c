#include <stdio.h>

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    int episodes[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            episodes[i][j] = 0;
        }
    }

    for (int i = 0; i < q; i++) {
        int e, s;
        scanf("%d %d", &e, &s);
        episodes[s - 1][e - 1] = 1;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (episodes[i][j] == 0) {
                k++;
            }
        }
    }

    printf("%d\n", k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (episodes[i][j] == 0) {
                printf("%d %d\n", j + 1, i + 1);
            }
        }
    }
}