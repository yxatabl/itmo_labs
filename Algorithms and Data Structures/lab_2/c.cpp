#include <iostream>

using namespace std;

void quicksort(long long* a, long long left, long long right) {
    long long key = a[(left + right)/2 + 1];
    long long i = left, j = right;

    while (i <= j){
        while (a[i] < key){
            i++;
        }
        while (a[j] > key){
            j--;
        }
        if (i <= j) {
            long long x = a[i];
            a[i] = a[j];
            a[j] = x;
            i++;
            j--;
        }
    }
    if (left < j){
        quicksort(a, left, j);
    }
    if (right > i){
        quicksort(a, i, right);
    }
}

int main(){
    long long n;
    cin >> n;

    long long mas[n];
    for (long long i = 0; i < n; i++){
        cin >> mas[i];
    }

    quicksort(mas, 0, n-1);

    long long s = 0;
    long long a = -1;

    for (long long i = n-1; i > 0; i--){
        if (mas[i] != 0){
            if (mas[i] == mas[i-1] || mas[i]-1 == mas[i-1]){
                if (a == -1){
                    a = mas[i-1];
                } else {
                    s += mas[i-1]*a;
                    a = -1;
                }
                mas[i-1] = 0;
            }
            mas[i] = 0;
        }
    }

    cout << s;

}