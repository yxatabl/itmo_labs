#include <iostream>

using namespace std;

void merge(long long arr[], long long arr2[], long long p, long long q, long long r) {
    long long n1 = q - p + 1;
    long long n2 = r - q;

    long long L[n1], M[n2];
    long long L2[n1], M2[n2];

    for (long long i = 0; i < n1; i++){
        L[i] = arr[p + i];
        L2[i] = arr2[p + i];
    }
    for (long long j = 0; j < n2; j++){
        M[j] = arr[q + 1 + j];
        M2[j] = arr2[q + 1 + j];
    }

    long long i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            arr2[k] = L2[i];
            i++;
        } else {
            arr[k] = M[j];
            arr2[k] = M2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        arr2[k] = M2[j];
        j++;
        k++;
    }
}

void mergeSort(long long arr[], long long arr2[], long long l, long long r) {
    if (l < r) {
        long long m = l + (r - l) / 2;

        mergeSort(arr, arr2, l, m);
        mergeSort(arr, arr2, m + 1, r);

        merge(arr, arr2, l, m, r);
    }
}

int main(){
    long long n, m, k;
    cin >> n >> m >>k;

    long long koefs[n];
    for (long long i = 0; i < n; i++){
        cin >> koefs[i];
    }

    long long ratings[m];
    long long films[m];
    long long rating;
    for (long long i = 0; i < m; i++){
        ratings[i] = 0;
        films[i] = i+1;
        for (long long j = 0; j < n; j++){
            cin >> rating;
            ratings[i] += rating*koefs[j];
            ratings[i] %= 1000000007;
        }
    }

    mergeSort(ratings, films, 0, m-1);

    for (long long i = 0; i < k; i++){
        cout << films[m-1-i] << " ";
    }
    
    return 0;
}