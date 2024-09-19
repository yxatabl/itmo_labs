#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long arr[n+1];
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int i = 1;
    bool ok = true;
    while (ok && (2*i <= n || 2*i+1 <= n)){
        if (2*i <= n && arr[i] > arr[2*i]){
            ok = false;
        }

        if (2*i+1 <= n && arr[i] > arr[2*i+1]){
            ok = false;
        }
        i++;
    }

    if (ok){
        cout << "YES";
    } else {
        cout << "NO";
    }

}