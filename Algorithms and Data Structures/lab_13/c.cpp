#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m;
    string text;
    int count = 0;
    cin >> n >> m >> text;
    for (int c = 0, i, j, k; c < m; c++){
        cin >> i >> j >> k;
        count += (text.substr(i-1, k) == text.substr(j-1, k)); 
    }
    cout << count;
}