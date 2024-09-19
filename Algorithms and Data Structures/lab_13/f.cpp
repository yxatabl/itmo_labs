#include <iostream>
#include <regex>
using namespace std;

int main(){
    int m;
    string str;
    regex exp(R"(^([A-Z][A-z]* ){3}\d\d (\+?7|8)\(?\d{3}\)?-?\d{3}-?\d{2}-?\d{2} g.[A-Z]{3}, ul.[A-Z][A-z]*, d.\d+$)");

    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++){
        getline(cin, str);
        regex_match(str, exp) ? cout << "YES\n" : cout << "NO\n";
    }
}