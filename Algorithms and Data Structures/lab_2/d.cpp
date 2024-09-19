#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int mas[n];
    
    for (int i = 0; i < n; i++){
        mas[i] = i+1;
    }

    for (int i = 2; i < n; i++){
        std::swap(mas[i], mas[i/2]);
    }

    for (int i = 0; i < n; i++){
        std:: cout << mas[i] << " ";
    }
}