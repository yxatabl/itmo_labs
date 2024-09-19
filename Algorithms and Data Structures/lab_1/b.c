#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int list [n];
    k = k%n;
    for (int i = 0; i < n-1; ++i) {
        if (i+k<=n-1) {
            if (i+k>=0){
                scanf("%d ", &list[i+k]);
            } else {
                scanf("%d ", &list[n+i+k]);
            }
        } else {
            scanf("%d ", &list[i+k-n]);
        }
    }
    if (n-1+k<=n-1) {
        if (n-1+k>=0){
            scanf("%d", &list[n-1+k]);
        } else {
            scanf("%d", &list[n+n-1+k]);
        }
    } else {
        scanf("%d", &list[n-1+k-n]);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", list[i]);
    }

}