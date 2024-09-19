#include <stdio.h>

int main(){
    int n;
    scanf("%d\n", &n);

    int mas[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &mas[i]);
    }

    int el;
    for (int i = 1; i < n; i++){
        for (int j = i; j>0 && mas[j-1]>mas[j]; j--){
            el = mas[j];
            mas[j] = mas[j-1];
            mas[j-1] = el;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d ", mas[i]);
    }
}