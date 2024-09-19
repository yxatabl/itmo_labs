#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char word[n];
    scanf("%s", word);

    for (int i = 0, j = n - 1; i < j; ++i, --j){
        if (word[i] != word[j]){

            if (word[i+1] != word[j]){
                if (word[i] != word[j-1]){
                    printf("NO");
                    return 0;
                }
            }

            printf("YES");
            return 0;
        }
    }

    printf("YES");
    return 0;
}