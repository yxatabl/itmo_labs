#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefixFunc(string str){
    vector<int> p = {0};
    for (int i = 1; i < str.length(); i++){
        int k = p[i-1];
        while ((k > 0) && (str[i] != str[k])) k = p[k-1];
        if (str[i] == str[k]) k++;
        p.push_back(k);
    }
    return p;
}

int main(){
    string str;
    cin >> str;
    for (int el : prefixFunc(str)) cout << el << " ";
}