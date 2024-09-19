#include <stdio.h>

int main(){
    int t, n, a, b, d, c;
    char o[3];

    scanf("%d", &t);
    for (int i = 0; i < t; ++i){
        scanf("%d", &n);
        b = 15;
        d = 30;

        for (int j = 0; j < n; ++j){
            scanf("%s %d", &o, &c);
            if (b <= d){
                if (o[0] == '>'){
                    if (c > b) {
                        b = c;
                    }
                } else {
                    if (c < d) {
                        d = c;
                    }
                }

                if (b>d){
                    printf("-1\n");
                } else {
                    printf("%d\n", b);
                }
            } else {
                printf("-1\n");
            }
            
        }
    }
}