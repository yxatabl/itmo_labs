#include <iostream>
#include <math.h>

using namespace std;

int g( int n ){
    return n ^ (n >> 1);
}

void print(int num, int n){
    char mas[n+1];
    int a = num;

    mas[n] = '\0';

    for (int i = n-1; i >= 0; i--){
        mas[i] = a%2 + '0';
        a = a/2;
    }

    cout << mas << "\n";
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < pow(2, n); i++){
        print(g(i), n);
    }
}