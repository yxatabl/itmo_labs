#include <iostream>

using namespace std;

void quicksort(int* a, int left, int right) {
    int key = a[(left + right)/2+1];
    int i = left, j = right;

    while (i <= j){
        while (a[i] < key){
            i++;
        }
        while (a[j] > key){
            j--;
        }
        if (i <= j) {
            int x = a[i];
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

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    quicksort(a, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}