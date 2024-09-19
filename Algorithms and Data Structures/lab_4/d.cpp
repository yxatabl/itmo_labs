#include <iostream>
#include <vector>

using namespace std;

struct city{
    long long code;
    long long data;
};
/*
void siftUp(vector<city> &vec, int i = -1){
    if (i == -1) i = vec.size()-1;

    while (i > 0 && (vec[i].data > vec[(i-1)/2].data) || ((vec[i].data == vec[(i-1)/2].data) && (vec[i].code < vec[(i-1)/2].code))){
        swap(vec[i], vec[(i-1)/2]);
        i = (i-1)/2;
    }
}

void siftDown(vector<city> &vec, int i = 0){
    while (2*i + 1 < vec.size()){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int j = l;
        if (r < vec.size() && (vec[r].data > vec[l].data || (vec[r].data == vec[l].data && vec[r].code < vec[l].code))){
            j = r;
        }
        if (vec[i].data > vec[j].data || (vec[i].data == vec[j].data && vec[i].code < vec[j].code)){
            break;
        }
        swap(vec[i], vec[j]);
        i = j;
    }
}
*/

void siftUp(vector<city> &vec, int i = -1){
    if (i == -1) i = vec.size() - 1;

    while (i > 0 && vec[(i-1)/2].data <= vec[i].data) {
            if (vec[i].data == vec[(i-1)/2].data && vec[i].code > vec[(i-1)/2].code) {
                swap(vec[i], vec[(i-1)/2]);
                i = (i-1)/2;
            }
            else if (vec[i].data > vec[(i-1)/2].data) {
                swap(vec[i], vec[(i-1)/2]);
                i = (i-1)/2;
            }
            else {
                break;
            }
    }
}

void siftDown(vector<city> &vec, int i = 0){
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;
    long long j = i;

    if (left < vec.size()){
        if (vec[left].data > vec[j].data) j = left;
        else if (vec[left].data == vec[j].data && vec[left].code > vec[j].code) j = left;
    }

    if (right < vec.size()){
        if (vec[right].data > vec[j].data) j = right;
        else if (vec[right].data == vec[j].data && vec[right].code > vec[j].code) j = right;
    }

    if (j != i) {
        swap(vec[i], vec[j]);
        siftDown(vec, j);
    }
}
city get(vector<city> &vec){
    city res;

    res = vec[0];
    vec[0] = vec[vec.size() - 1];
    vec.pop_back();
    siftDown(vec);

    return res;
}

int main(){
    long long n, code, rat, mon;
    vector<city> rating;
    vector<city> money;
    city cityRat, cityMon;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> code >> rat >> mon;

        cityRat.code = code;
        cityRat.data = rat;
        rating.push_back(cityRat);
        siftUp(rating);

        cityMon.code = code;
        cityMon.data = mon;
        money.push_back(cityMon);
        siftUp(money);
    }

    int m;
    cin >> m;
    bool answers[m];
    char inp[5];
    for (int i = 0; i < m; i++){
        cin >> inp;
        answers[i] = (inp[0] == 'Y');
    }

    int tourInd = 0;
    int ansInd = 0;
    long long tourCities[n];
    bool prevEqual = true;
    while (rating.size() > 0){
        cityRat = get(rating);
        
        if (prevEqual){
            cityMon = get(money);
        }

        if (cityRat.code == cityMon.code){
            tourCities[tourInd] = cityRat.code;
            tourInd++;
            prevEqual = true;
        } else if (ansInd < m && answers[ansInd]){
            tourCities[tourInd] = cityRat.code;
            tourInd++;
            ansInd++;
            cout << cityRat.code << " ";
            prevEqual = false;
        } else {
            if (ansInd < m) cout << cityRat.code << " ";
            prevEqual = false;
            ansInd++;
        }
    }
    cout << "\n";

    for (int i = 0; i < tourInd; i++){
        cout << tourCities[i] << " ";
    }
}