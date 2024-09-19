#include <stdio.h>

int main() {
    int n, a, s, r;
    scanf("%d\n", &n);

    int mas[n];

    s = 0;
    a = 0;
    r = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &mas[i]);
        s += mas[i];
        if (i > 0){
            r += mas[i];
        }
    }
    if (r == 0){
        printf("0");
        return 0;
    }
    r = -1;
    s -= mas[0];
    for (int i = 1; i < n-1; ++i) {
        a+=mas[i-1];
        s-=mas[i];
        if (a == s) {
            r = i;
            break;
        }
    }
    printf("%d", r);
}