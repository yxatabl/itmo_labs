#include <iostream>

using namespace std;

int insertionSort(long long arr[], int n){
    long long el;
    int i, j;
    for (i = 1; i < n; i++){
        el = arr[i];
        for (j = i-1; j >= 0 && arr[j]-1 >= el; j--){
            if (arr[j]-1 == el){
                return 0;
            }
            arr[j+1] = arr[j]-1;
            el += 1;
        }
        arr[j+1] = el;
    }
    return 1;
}

int main(){
    int n;
    cin >> n;

    long long mas[n];
    for (int i = 0; i < n; i++){
        cin >> mas[i];
    }

    int a = insertionSort(mas, n);

    if (a == 0){
        cout << ":(";
        return 0;
    }

    for (int i = 0; i < n; i++){
        cout << mas[i] << " ";
    }
    return 0;

}