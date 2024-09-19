#include <iostream>
#include <ios>
#include <vector>
#include <cstring>

using namespace std;

void siftUp(vector <long long> &vec, int i){
    while (i > 0 && vec[i] < vec[(i-1)/2]){
        swap(vec[i], vec[(i-1)/2]);
        i = (i-1)/2;
    }
}

void siftDown(vector <long long> &vec, int i){
    while (2*i + 1 < vec.size()){
        int left = 2*i + 1;
        int right = 2*i + 2;

        int j = left;
        if (right < vec.size() && vec[right] < vec[left]) j = right;
        if (vec[i] <= vec[j]) break;

        swap(vec[i], vec[j]);
        i = j;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<long long>> base;
    char command[13];
    long long a, b, c;

    while (cin >> command){

        if (!strcmp(command, "create")){
            vector <long long> vec;
            base.push_back(vec);

        } else if (!strcmp(command, "insert")){
            cin >> a;
            cin >> b;

            base[a].push_back(b);
            siftUp(base[a], base[a].size()-1);

        } else if (!strcmp(command, "extract-min")){
            cin >> a;

            if (base[a].size() == 0){
                cout << "*\n";
            } else {
                long long val = base[a][0];
                cout << val << "\n";
                base[a][0] = base[a].back();
                base[a].pop_back();
                siftDown(base[a], 0);
            }

        } else if (!strcmp(command, "merge")){
            cin >> a;
            cin >> b;

            vector <long long> vec = base[a];
            base.push_back(vec);

            for (int i = 0; i < base[b].size(); i++){
                base.back().push_back(base[b][i]);
                siftUp(base.back(), base.back().size()-1);
            }

        } else if (!strcmp(command, "decrease-key")){
            cin >> a;
            cin >> b;
            cin >> c;

            for (int i = 0; i < base[a].size(); i++){
                if (base[a][i] == b){
                    base[a][i] = c;
                    siftUp(base[a], i);
                    break;
                }
            }
        }
    }
}