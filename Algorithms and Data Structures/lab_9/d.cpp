#include <iostream>
#include <vector>

using namespace std;

const unsigned long long INF = ULLONG_MAX;

int main(){
    unsigned long long n, m;
    cin >> n >> m;

    vector<vector<unsigned long long>> d(n, vector<unsigned long long>(n, INF));
    
    for (unsigned int i = 0; i < d.size(); i++) d[i][i] = 0;

    unsigned long long x, y, t;
    for (unsigned long long i = 0; i < m; i++){
        cin >> x >> y >> t;
        d[x-1][y-1] = min(t, d[x-1][y-1]);
        d[y-1][x-1] = min(t, d[y-1][x-1]);
    }

    for (unsigned long long k = 0; k < n; k++){
        for (unsigned long long i = 0; i < n; i++){
            for (unsigned long long j = 0; j < n; j++){
                if (d[i][k] < INF && d[k][j] < INF) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    unsigned long long res = -2;
    unsigned long long rsum = INF;
    unsigned long long sum;
    for (unsigned long long i = 0; i < n; i++){
        sum = 0;
        for (unsigned long long j = 0; j < n; j++) sum+=d[i][j];
        if (sum < rsum){
            res = i;
            rsum = sum;
        }
    }

    cout << res+1;
}