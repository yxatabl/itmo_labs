#include <iostream>
#include <vector>

using namespace std;

struct worker{
    long long salary;
    long long end = 0;
};

void siftUpFree(vector <worker> &vec, int i = -1){
    if (i == -1){
        i = vec.size()-1;
    }
    while (i > 0 && vec[i].salary < vec[(i-1)/2].salary){
        swap(vec[i], vec[(i-1)/2]);
        i = (i-1)/2;
    }
}

void siftUpInwork(vector <worker> &vec, int i = -1){
    if (i == -1){
        i = vec.size()-1;
    }
    while (i > 0 && vec[i].end < vec[(i-1)/2].end){
        swap(vec[i], vec[(i-1)/2]);
        i = (i-1)/2;
    }
}

void siftDownFree(vector <worker> &vec, int i = 0){
    while (2*i + 1 < vec.size()){
        int left = 2*i + 1;
        int right = 2*i + 2;

        int j = left;
        if (right < vec.size() && vec[right].salary < vec[left].salary) j = right;
        if (vec[i].salary <= vec[j].salary) break;

        swap(vec[i], vec[j]);
        i = j;
    }
}

void siftDownInwork(vector <worker> &vec, int i = 0){
    while (2*i + 1 < vec.size()){
        int left = 2*i + 1;
        int right = 2*i + 2;

        int j = left;
        if (right < vec.size() && vec[right].end < vec[left].end) j = right;
        if (vec[i].end <= vec[j].end) break;

        swap(vec[i], vec[j]);
        i = j;
    }
}

int main(){
    long long n, m;
    cin >> n >> m;

    vector<worker> inwork;
    vector<worker> free;
    long long sal;
    for (int i = 0; i < n; i++){
        worker w;
        cin >> sal;
        w.salary = sal;
        free.push_back(w);

        siftUpFree(free);
    }

    long long t, f;
    long long salary = 0;
    for (int i = 0; i < m; i++){
        cin >> t >> f;

        while (inwork.size() > 0 && inwork[0].end <= t){
            worker w;

            w = inwork[0];
            swap(inwork[0], inwork[inwork.size() - 1]);
            inwork.pop_back();
            siftDownInwork(inwork);

            free.push_back(w);
            siftUpFree(free);
        }

        if (free.size() > 0){
            worker w;

            w = free[0];
            swap(free[0], free[free.size()-1]);
            free.pop_back();
            siftDownFree(free);

            salary += f*w.salary;
            w.end = t+f;

            inwork.push_back(w);
            siftUpInwork(inwork);
        }
    }

    cout << salary;
}