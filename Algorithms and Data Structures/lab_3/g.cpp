#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = a[n - 1] - a[0];
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 1, left = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - left >= mid) {
                cnt++;
                left = a[i];
            }
        }
        if (cnt >= k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}