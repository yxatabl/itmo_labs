#include "blazingio.hpp"
#include <vector>
using namespace std;

long long getHash(vector<long long> vec){
    long long s = 0;
    const long long d = (long long) 293;
    for (long long el : vec){
        s += el^d;
    }
    return s;
}

int main(){
    int n;
    long long el;
    
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> el;
        a.push_back(el);
    }
    for (int i = 0; i < n; i++){
        cin >> el;
        b.push_back(el);
    }

    getHash(a) == getHash(b) ? cout << "YES" : cout << "NO";
}