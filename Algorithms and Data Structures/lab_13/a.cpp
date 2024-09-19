#include <iostream>
#include <vector>
#include <string>
using namespace std;

string t, x;
vector<int> pos;

int main(){
	cin >> t >> x;
	int count = 0;
	for (int i = 0; i < t.size()-x.size()+1; i++){
		if (t.substr(i, x.size()) == x){
			count++;
			pos.push_back(i);
		}
	}
	cout << count << "\n";
	for (int p : pos) cout << p << " ";
	return 0;
}