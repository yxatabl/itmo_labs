#include <iostream>
using namespace std;

long long merge(int mas[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1];
    int R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = mas[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = mas[mid + 1 + j];
    }
    
    long long kol = 0;
    
    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            mas[k] = L[i];
            i++;
        } else {
            mas[k] = R[j];
            j++;
            kol += n1 - i;
        }
        k++;
    }
    
    while (i < n1) {
        mas[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        mas[k] = R[j];
        j++;
        k++;
    }
    
    return kol;
}

long long mergeSort(int mas[], int left, int right) {
    long long kol = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        kol += mergeSort(mas, left, mid);
        kol += mergeSort(mas, mid + 1, right);
        kol += merge(mas, left, mid, right);
    }
    
    return kol;
}

int main() {
    int n;
    cin >> n;
    
    int mas[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    
    long long kol = mergeSort(mas, 0, n - 1);
    
    cout << kol;
    
    return 0;
}