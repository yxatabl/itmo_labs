#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> g1, g2;
    int n;
    cin >> n;
    g1.resize(n, 0);
    g2.resize(n, 0);
    for (int i = 0, a, b; i < n-1; i++){
        cin >> a >> b;
        g1[a-1]++;
        g1[b-1]++;
    }
    for (int i = 0, a, b; i < n-1; i++){
        cin >> a >> b;
        g2[a-1]++;
        g2[b-1]++;
    }
    int h1 = 0, h2 = 0;
    for (int x : g1){
        h1 += x ^ 50021;
    }
    for (int x : g2){
        h2 += x ^ 50021;
    }
    h1 == h2 ? cout << "YES" : cout << "NO";
}