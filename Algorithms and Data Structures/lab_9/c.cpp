#include <vector>
#include <iostream>

using namespace std;

const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    int a, b, t;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> t;
        g[a-1].push_back({b-1, t});
    }
    int s = 0;
    vector<int> d (n, INF), p(n);
    d[s] = 0;
    vector<char> u(n);
    for (int i = 0; i < n; i++){
        int v = -1;
        for (int j = 0; j < n; j++){
            if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        if (d[v] == INF) break;
        u[v] = true;
        for (size_t j = 0; j < g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to]){
                d[to] = d[v]+len;
                p[to] = v;
            }
        }
    }

    int res = d[d.size()-1];
    res == INF ? cout << -1 : cout << res;
}